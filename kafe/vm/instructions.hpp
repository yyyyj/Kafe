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
        INST_DOUBLE      = 0x03,  // 0x03 [double on *I-don't-know-how-many-bytes*]
        INST_STR         = 0x04,  // 0x04 [string size on 2 bytes] [text]
        INST_BOOL        = 0x05,  // 0x05 [value on 1 byte] ; if value > 0x00 => true
        INST_ADDR        = 0x06,  // 0x06 [size of a segment name on 2 bytes] [name] ; used to store the address of a segment (kind of pointer, only pointing on something in the bytecode)
        INST_LIST        = 0x07,  // 0x07 [number of elements on 4 bytes = X] ; takes the X last elements put on the stack and put them into a list
        INST_VAR         = 0x08,  // 0x08 [var name size on 2 bytes] [name]
        INST_STRUCT      = 0x09,  // 0x09 [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
        INST_DECL_STRUCT = 0x0a,  // 0x0a [struct name size on 2 bytes] [name] [number of pair<Value::Var, Value> = X] ; read X pair from the stack, var_name=stack[-1], value=stack[-2]
        INST_STRUCT_GETM = 0x0b,  // 0x0b [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; push the value of the member (if it exists) onto the stack
        INST_STRUCT_SETM = 0x0c,  // 0x0c [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; takes the last value on the stack and put it into the member (if it exists or not)
        INST_STRUCT_HASM = 0x0d,  // 0x0d [struct name size on 2 bytes] [name] [member name on 2 bytes] [name] ; check if the struct has a member "name" : push true or false

        // labels and blocs
        INST_SEGMENT     = 0x10,  // 0x10 [segment name size on 2 bytes] [name] [size (from the next byte after this 2, to the INST_RET included) on 2 bytes]
        INST_DECL_SEG    = 0x11,  // 0x11 [segment name size on 2 bytes] [name] [position on 2 bytes]
        INST_STORE_VAR   = 0x12,  // 0x12 ; store the value at stack[-2] in stack[-1]
        INST_LOAD_VAR    = 0x13,  // 0x13 [var name size on 2 bytes] [name] ; push its value on the stack
        INST_DUP         = 0x14,  // 0x14 ; duplicate the value at stack[-1]
        INST_JUMP        = 0x15,  // 0x15 [segment name size on 2 bytes] [name]
        INST_JUMP_IF     = 0x16,  // 0x16 [size of the segment name on 2 bytes] [name] ; jump if stack[-1] compares to true
        INST_JUMP_IFN    = 0x17,  // 0x17 [size of the segment name on 2 bytes] [name] ; jump if stack[-1] compares to false
        INST_RET         = 0x18,  // 0x18 ; return from a segment

        // built-in procedures around numbers and booleans
        INST_PROCEDURE   = 0x20,
    };

    enum Procedure
    {
        // [CODE] ; push the result of stack[-2] [OPERATOR] stack[-1]    OR    push the result of [OPERATOR] stack[-1]
        INST_ADD       = 0x01,  // 0x01 ; push the result of stack[-2] + stack[-1]
        /// to implement !
            INST_SUB       = 0x02,  // 0x02 ; -
            INST_DIV       = 0x03,  // 0x03 ; /
            INST_MUL       = 0x04,  // 0x04 ; *
            INST_MOD       = 0x05,  // 0x05 ; %
            INST_INC       = 0x06,  // 0x06 ; ++
            INST_DEC       = 0x07,  // 0x07 ; --
            INST_NEG       = 0x08,  // 0x08 ; - (negate, not subtract)
            INST_BIN_AND   = 0x09,  // 0x09 ; &
            INST_BIN_OR    = 0x0a,  // 0x0a ; |
            INST_BIN_NOT   = 0x0b,  // 0x0b ; ~
            INST_LSHIFT    = 0x0c,  // 0x0c ; <<
            INST_RSHIFT    = 0x0d,  // 0x0d ; >>
            INST_BIN_XOR   = 0x0e,  // 0x0e ; ^
            INST_AND       = 0x0f,  // 0x0f ; &&
            INST_OR        = 0x10,  // 0x10 ; ||
            INST_NOT       = 0x11,  // 0x11 ; !
            INST_LW        = 0x12,  // 0x12 ; <
            INST_LE        = 0x13,  // 0x13 ; <=
            INST_GR        = 0x14,  // 0x14 ; >
            INST_GE        = 0x15,  // 0x15 ; >=
            INST_EQ        = 0x16,  // 0x16 ; ==
        // done :
        INST_NE        = 0x17,  // 0x17 ; !=

        // built-in functions
        /// to implement !
        // print, getchar, getline
    };

}  // namespace kafe

#endif // kafe_inst
