# VM

## Bytecode instructions

### Types

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_INT_2B      = 0x01 | 0x01 [integer on 2 bytes]
INST_INT_4B      = 0x02 | 0x02 [integer on 4 bytes]
INST_DOUBLE      = 0x03 | 0x03 [integer part on 4 bytes] [exponent on 2 bytes (max value is +/- 308)]
INST_STR         = 0x04 | 0x04 [string size on 2 bytes] [text]
INST_BOOL        = 0x05 | 0x05 [value on 1 byte] ; if value > 0x00 => true
INST_ADDR        = 0x06 | 0x06 [size of a segment name on 2 bytes] [name] ; used to store the address of a segment (kind of pointer, only pointing on something in the bytecode)
INST_LIST        = 0x07 | 0x07 [number of elements on 4 bytes = X] ; takes the X last elements put on the stack and put them into a list
INST_VAR         = 0x08 | 0x08 [var name size on 2 bytes] [name]
INST_STRUCT      = 0x09 | 0x09 [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
INST_DECL_STRUCT = 0x0a | 0x0a [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
INST_STRUCT_GETM = 0x0b | 0x0b [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; push the value of the member (if it exists) onto the stack
INST_STRUCT_SETM = 0x0c | 0x0c [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; takes the last value on the stack and put it into the member (if it exists or not)
INST_STRUCT_HASM = 0x0d | 0x0d [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; check if the struct has a member "name" : push true or false
INST_DEL_VAR     = 0x0f | 0x0f [var name size on 2 bytes] [name]

### Segment and Blocs

Instruction code  | Use in the bytecode
----------------- | -------------------
INST_SEGMENT     = 0x10 | 0x10 [segment name size on 2 bytes] [name] [size (from the next byte after this 2, to the INST_RET included) on 2 bytes]
INST_DECL_SEG    = 0x11 | 0x11 [segment name size on 2 bytes] [name] [position on 2 bytes]
INST_STORE_VAR   = 0x12 | 0x12 ; store the value at stack[-2] in stack[-1]
INST_LOAD_VAR    = 0x13 | 0x13 [var name size on 2 bytes] [name] ; push its value on the stack
INST_DUP         = 0x14 | 0x14 ; duplicate the value at stack[-1]
INST_JUMP        = 0x15 | 0x15 [segment name size on 2 bytes] [name]
INST_JUMP_IF     = 0x16 | 0x16 [size of the segment name on 2 bytes] [name] ; jump if stack[-1] compares to true
INST_JUMP_IFN    = 0x17 | 0x17 [size of the segment name on 2 bytes] [name] ; jump if stack[-1] compares to false
INST_RET         = 0x18 | 0x18 ; return from a segment

### Built-in procedures around numbers and booleans
Instruction code  | Use in the bytecode
----------------- | -------------------
INST_PROCEDURE   = 0x20 | 0x20 [instruction code on 2 bytes]

#### Procedures code
[CODE] | push the result of stack[-2] [OPERATOR] stack[-1] OR push the result of [OPERATOR] stack[-1]
------ | --------------------------------------------------------------------------------------------
INST_ADD       = 0x0001 | 0x0001 ; push the result of stack[-2] + stack[-1]
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
