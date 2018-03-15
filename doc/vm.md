# VM

## Internal behaviour

The Kafe VM is relying on a caching system for `Value`s, the `BytecodeBlocksMaker`, to speed up the process of reading bytes, assembling them into either a number, a boolean, a string...

It is implements a call stack to keep track of all the function calls, using a vector of `kafe::Call` objects, storing a bunch of useful things (as well as their own variables table), but this costs memory. Indeed a single `kafe::Call` object weighs 52B (in Release mode using VS17). This means you have to be careful when creating recursive algorithms to avoid an OutOfMemory like exception.

The definitions of the objects (called *structures* in the VM) are stored in an `unordered_map<string, Structure>`, (each `Structure` object weighs 24B, under the same conditions as before), and a `Structure` object is composed of a list of the ID of its parents (see below for more explanations) and a list of `StructElem` representing the members of the objects. A `StructElem` is mapping a string and a `Value`, consequently searching for a specific member in a `Structure` is O(n).

### Inheritance

As said before, a `Structure` is holding a list of the ID of its parents. For example, if we have :

```
    Obj A
      |
    --+--
    v   v
Obj B   Obj C
    |       |
    |       |
    v       +---
Obj D       v   v
        Obj E   Obj F
```

*Each object get an ID when it is defined, calculated so that ID(new Obj) = ++Global ID.*

Here we get :

Obj | ID
----|----
Obj A | 1
Obj B | 2
Obj C | 3
Obj D | 4
Obj E | 5
Obj F | 6

F will have those IDs : `[1, 3, 6]`, will D would have `[1, 2, 4]`.

When an object is inheriting from another (can only be done when the object is defined), it *earns* all the attributes of the parent object, which means there are no needs for a `super().__init__()` as in Python.

### Structures filling

Consider this Kafe source code :

```
Obj A
    dyn a
    dyn b
    dyn c = 15  # a default value for c

    # more stuff here, for examples methods
end

dyn instance_of_A1 : A(5)
dyn instance_of_A2 : A(5, 6)
dyn instance_of_A3 : A(5, 6, 7)
```

Each of the 3 declarations of objects of type `A` are valid, because the values are filled in order they appear, and if one (or more) are missing, they just keep their default values. Just take note that a function inside an object (alias a member function of an object) is considered as a regular member of the object, as well a `a`, `b` or `c` in our example, because they are represented using an address pointing to a segment of bytecode. A guard should prevent the user from doing this kind of silly stuff :

```
Obj B
    dyn a

    fun test() -> int
        ret 0
end

dyn prank : B(5, 14000)
```

If we apply what we said before, `test()` is an address, for example `0xabcdef`, and by doing `dyn prank : B(5, 14000)` it should get the value `14000` instead of keeping its old value (`0xabcdef`). It's the role of the guard to prevent those kinds of thing to happen (it must crash the app if you are trying to do so).

## Bytecode instructions

Below, you can find all the byte codes used by the VM and how they are supposed to work.

### Types

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_INT_2B      = 0x01 | 0x01 [integer on 2 bytes]
INST_INT_4B      = 0x02 | 0x02 [integer on 4 bytes]
INST_INT_8B      = 0x03 | 0x03 [integer on 8 bytes]
INST_DOUBLE      = 0x04 | 0x04 [integer part on 4 bytes] [exponent on 2 bytes (max value is +/- 308)]
INST_STR         = 0x05 | 0x05 [string size on 2 bytes] [text]
INST_BOOL        = 0x06 | 0x06 [value on 1 byte] ; if value > 0x00 => true
INST_ADDR        = 0x07 | 0x07 [size of a segment name on 2 bytes] [name] ; used to store the address of a segment (kind of pointer, only pointing on something in the bytecode)
INST_LIST        = 0x08 | 0x08 [number of elements on 4 bytes = X] ; takes the X last elements put on the stack and put them into a list
INST_VAR         = 0x09 | 0x09 [var name size on 2 bytes] [name]
INST_EMPTY       = 0x0a | 0x0a ; create a Value of ValueType::Empty (useful for const variables)

### Structures (alias Obj)

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_STRUCT      = 0x10 | 0x10 [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
INST_DECL_STRUCT = 0x11 | 0x11 [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
INST_STRUCT_GETM = 0x12 | 0x12 [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; push the value of the member (if it exists) onto the stack
INST_STRUCT_SETM = 0x13 | 0x13 [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; takes the last value on the stack and put it into the member (if it exists or not)
INST_STRUCT_HASM = 0x14 | 0x14 [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; check if the struct has a member "name" : push true or false
INST_STRUCT_HASPARENT = 0x15 | 0x15 [parent name] [name] ; check if parent name (can either be an instantiated struct or not) is a parent of name (must be instantiated this time)
INST_STRUCT_TID  = 0x16 | 0x16 [name] ; push the type id (integer) of a struct "name" on the stack

### Variables

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_STORE_DYN   = 0x20 | 0x20 ; store the value at stack[-2] in stack[-1] (create a DYN variable)
INST_STORE_CST   = 0x21 | 0x21 ; store the value at stack[-2] in stack[-1] (create a CONST variable)
INST_LOAD_VAR    = 0x22 | 0x22 [name] ; push its value on the stack
INST_DEL_VAR     = 0x23 | 0x23 [name] ; delete the selected variable
INST_NONLOCAL    = 0x24 | 0x24 [name] ; set a global scope variable as local scope variable with writing permissions (only in segments)
INST_GET_TYPE    = 0x25 | 0x25 [name] ; name must a living variable in the current scope. push the string version of the type name. return "struct" for the structures

### Lists

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_SIZE_LST    = 0x30  | 0x30 ; push the size, on the stack, of the list at stack[-1]
INST_POP_LST     = 0x31  | 0x31 [integer on 6 bytes = X] ; pop the element at stack[-1][X] (stack[-1] must be a list), handling negatives indexes. raises an exception if the index isn't in range
INST_APPEND_LST  = 0x32 | 0x32 ; push the element at stack[-2] in the list at stack[-1]
INST_GNTH_LST    = 0x33 |  0x33 [integer on 6 bytes = X] ; push on the stack the elemenet at stack[-1][X] (stack[-1] must be a list), handling negatives indexes. raises an exception if the index isn't in range
INST_SNTH_LST    = 0x34 |  0x34 [integer on 6 bytes = X] ; push the element at stack[-2] in stack[-1][X] (which must be a list). raises and exception if stack[-1] isn't a list
INST_GSLICE_LST  = 0x35 |  0x35 [integer on 6 bytes = X] [integer on 6 bytes = Y] [integer on 6 bytes = P] ; push the value of stack[-1][X:Y:P] on the stack. the values touched are in [X, Y[ with a step of P. raises an exception if X > Y or stack[-1] isn't a list
INST_SSLICE_LST  = 0x36 |  0x36 [integer on 6 bytes = X] [integer on 6 bytes = Y] [integer on 6 bytes = P] ; set the value of stack[-1][X:Y:P] as stack[-2], each one must be lists (raises an exception if not, also if the indexes aren't correct)
INST_CONS_LST    = 0x37 |  0x37 ; construct a new list from the objects x and y, with x=stack[-2] and y=stack[-1]

### Segments and blocs

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_DUP         = 0x40 | 0x40 ; duplicate the value at stack[-1]
INST_CALL        = 0x41 | 0x41 ; jump to stack[-1] (Value::Addr) and return to the caller position when `ret` is hit
INST_JUMP        = 0x42 | 0x42 ; jump to stack[-1] (Value::Addr) and continue the execution
INST_JUMP_IF     = 0x43 | 0x43 ; jump to stack[-2] (Value::Addr) if stack[-1] compares to true and continue the execution
INST_JUMP_IFN    = 0x44 | 0x44 ; jump to stack[-2] (Value::Addr) if stack[-1] compares to false and continue the execution
INST_RET         = 0x45 | 0x45 ; return from a segment
INST_GET_CWA     = 0x46 | 0x46 ; push the current address in the bytecode on the stack as a Value::Addr (CWA stands for current working address)
INST_PERMUTATION = 0x47 | 0x47 ; switch the two top values of the stack
INST_POP         = 0x48 | 0x48 ; pop the value off the stack (delete it)
INST_HALT        = 0x49 | 0x49 ; end the execution of the script

### Built-in procedures and user defined methods

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_PROCEDURE   = 0x50 | 0x50 [procedure code on 2 bytes]
INST_USER_PROC   = 0x51 | 0x51 [name] [number of arguments on 1 byte = X] ; 0 <= X <= ??

#### Procedures code
[CODE] | push the result of stack[-2] [OPERATOR] stack[-1] OR push the result of [OPERATOR] stack[-1]
------ | --------------------------------------------------------------------------------------------
INST_ADD       = 0x0001 | 0x0001 ; +
INST_SUB       = 0x0002 | 0x0002 ; -
INST_DIV       = 0x0003 | 0x0003 ; /
INST_MUL       = 0x0004 | 0x0004 ; *
INST_MOD       = 0x0005 | 0x0005 ; %
INST_INC       = 0x0006 | 0x0006 ; ++
INST_DEC       = 0x0007 | 0x0007 ; --
INST_NEG       = 0x0008 | 0x0008 ; - (negate, not subtract)
INST_BIN_AND   = 0x0009 | 0x0009 ; &
INST_BIN_OR    = 0x000a | 0x000a ; |
INST_BIN_NOT   = 0x000b | 0x000b ; ~
INST_LSHIFT    = 0x000c | 0x000c ; <<
INST_RSHIFT    = 0x000d | 0x000d ; >>
INST_BIN_XOR   = 0x000e | 0x000e ; ^
INST_AND       = 0x000f | 0x000f ; &&
INST_OR        = 0x0010 | 0x0010 ; ||
INST_NOT       = 0x0011 | 0x0011 ; !
INST_LW        = 0x0012 | 0x0012 ; <
INST_LE        = 0x0013 | 0x0013 ; <=
INST_GR        = 0x0014 | 0x0014 ; >
INST_GE        = 0x0015 | 0x0015 ; >=
INST_EQ        = 0x0016 | 0x0016 ; ==
INST_NE        = 0x0017 | 0x0017 ; !=
