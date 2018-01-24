#ifndef kafe_inst
#define kafe_inst

#include "../types.hpp"

namespace kafe
{

    enum Instruction
    {
        /// Constant name = value, // how to use it ; behaviour
        // types
        INST_INT_2B      = 0x01,  // 0x01 [integer on 2 bytes]
        INST_INT_4B      = 0x02,  // 0x02 [integer on 4 bytes]
        INST_INT_8B      = 0x03,  // 0x03 [integer on 8 bytes]
        INST_DOUBLE      = 0x04,  // 0x04 [integer part on 4 bytes] [exponent on 2 bytes (max value is +/- 308)]
        INST_STR         = 0x05,  // 0x05 [string size on 2 bytes] [text]
        INST_BOOL        = 0x06,  // 0x06 [value on 1 byte] ; if value > 0x00 => true
        INST_ADDR        = 0x07,  // 0x07 [size of a segment name on 2 bytes] [name] ; used to store the address of a segment (kind of pointer, only pointing on something in the bytecode)
        INST_LIST        = 0x08,  // 0x08 [number of elements on 4 bytes = X] ; takes the X last elements put on the stack and put them into a list
        INST_VAR         = 0x09,  // 0x09 [var name size on 2 bytes] [name]
        INST_STRUCT      = 0x0a,  // 0x0a [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
        INST_DECL_STRUCT = 0x0b,  // 0x0b [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
        INST_STRUCT_GETM = 0x0c,  // 0x0c [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; push the value of the member (if it exists) onto the stack
        INST_STRUCT_SETM = 0x0d,  // 0x0d [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; takes the last value on the stack and put it into the member (if it exists or not)
        INST_STRUCT_HASM = 0x0e,  // 0x0e [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; check if the struct has a member "name" : push true or false
        INST_DEL_VAR     = 0x0f,  // 0x0f [var name size on 2 bytes] [name]
        // segments and blocs
        INST_SEGMENT     = 0x10,  // 0x10 [segment name size on 2 bytes] [name] [size (from the next byte after these 4, to the INST_RET included) on 4 bytes]
        INST_STORE_VAR   = 0x11,  // 0x11 ; store the value at stack[-2] in stack[-1]
        INST_LOAD_VAR    = 0x12,  // 0x12 [var name size on 2 bytes] [name] ; push its value on the stack
        INST_DUP         = 0x13,  // 0x13 ; duplicate the value at stack[-1]
        INST_CALL        = 0x14,  // 0x14 [segment name size on 2 bytes] [name] ; jump and return to the caller position when `ret` is hit
        INST_JUMP        = 0x15,  // 0x15 [segment name size on 2 bytes] [name] ; jump and continue the execution
        INST_JUMP_IF     = 0x16,  // 0x16 [segment name size on 2 bytes] [name] ; jump if stack[-1] compares to true and continue the execution
        INST_JUMP_IFN    = 0x17,  // 0x17 [segment name size on 2 bytes] [name] ; jump if stack[-1] compares to false and continue the execution
        INST_RET         = 0x18,  // 0x18 ; return from a segment
        INST_GET_CWA     = 0x19,  // 0x19 ; push the current address in the bytecode on the stack as a Value::Addr (CWA stands for current working address)
        INST_GOTO        = 0x1a,  // 0x1a ; takes the last value on the stack, which should be a Value::Addr and jump to it

        // built-in procedures around numbers and booleans
        INST_PROCEDURE   = 0x20,
    };

    enum Procedure
    {
        // [CODE] ; push the result of stack[-2] [OPERATOR] stack[-1]    OR    push the result of [OPERATOR] stack[-1]
        INST_ADD       = 0x0001,  // 0x0001 ; +
        /// to implement !
            INST_SUB       = 0x0002,  // 0x0002 ; -
            INST_DIV       = 0x0003,  // 0x0003 ; /
            INST_MUL       = 0x0004,  // 0x0004 ; *
            INST_MOD       = 0x0005,  // 0x0005 ; %
            INST_INC       = 0x0006,  // 0x0006 ; ++
            INST_DEC       = 0x0007,  // 0x0007 ; --
            INST_NEG       = 0x0008,  // 0x0008 ; - (negate, not subtract)
            INST_BIN_AND   = 0x0009,  // 0x0009 ; &
            INST_BIN_OR    = 0x000a,  // 0x000a ; |
            INST_BIN_NOT   = 0x000b,  // 0x000b ; ~
            INST_LSHIFT    = 0x000c,  // 0x000c ; <<
            INST_RSHIFT    = 0x000d,  // 0x000d ; >>
            INST_BIN_XOR   = 0x000e,  // 0x000e ; ^
            INST_AND       = 0x000f,  // 0x000f ; &&
            INST_OR        = 0x0010,  // 0x0010 ; ||
            INST_NOT       = 0x0011,  // 0x0011 ; !
            INST_LW        = 0x0012,  // 0x0012 ; <
            INST_LE        = 0x0013,  // 0x0013 ; <=
            INST_GR        = 0x0014,  // 0x0014 ; >
            INST_GE        = 0x0015,  // 0x0015 ; >=
            INST_EQ        = 0x0016,  // 0x0016 ; ==
        // done :
        INST_NE        = 0x0017,  // 0x0017 ; !=

        // built-in functions
        /// to implement !
        // print, getchar, getline
    };

}  // namespace kafe

#endif // kafe_inst
