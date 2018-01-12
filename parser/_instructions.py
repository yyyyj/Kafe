# coding : utf-8

INSTRUCTIONS = {
    # types
    "INST_INT_2B"      : 0x01,
    "INST_INT_4B"      : 0x02,
    "INST_DOUBLE"      : 0x03,
    "INST_STR"         : 0x04,
    "INST_BOOL"        : 0x05,
    "INST_ADDR"        : 0x06,
    "INST_LIST"        : 0x07,
    "INST_VAR"         : 0x08,
    "INST_STRUCT"      : 0x09,
    "INST_DECL_STRUCT" : 0x0a,
    "INST_STRUCT_GETM" : 0x0b,
    "INST_STRUCT_SETM" : 0x0c,
    "INST_STRUCT_HASM" : 0x0d,

    "INST_DEL_VAR"     : 0x0f,

    # segments and blocs
    "INST_SEGMENT"     : 0x10,
    "INST_DECL_SEG"    : 0x11,
    "INST_STORE_VAR"   : 0x12,
    "INST_LOAD_VAR"    : 0x13,
    "INST_DUP"         : 0x14,
    "INST_JUMP"        : 0x15,
    "INST_JUMP_IF"     : 0x16,
    "INST_JUMP_IFN"    : 0x17,
    "INST_RET"         : 0x18,

    # built-in procedures around numbers and booleans
    "INST_PROCEDURE"   : 0x20
}

PROCEDURES = {
    "INST_ADD"       : 0x01,
    "INST_SUB"       : 0x02,
    "INST_DIV"       : 0x03,
    "INST_MUL"       : 0x04,
    "INST_MOD"       : 0x05,
    "INST_INC"       : 0x06,
    "INST_DEC"       : 0x07,
    "INST_NEG"       : 0x08,
    "INST_BIN_AND"   : 0x09,
    "INST_BIN_OR"    : 0x0a,
    "INST_BIN_NOT"   : 0x0b,
    "INST_LSHIFT"    : 0x0c,
    "INST_RSHIFT"    : 0x0d,
    "INST_BIN_XOR"   : 0x0e,
    "INST_AND"       : 0x0f,
    "INST_OR"        : 0x10,
    "INST_NOT"       : 0x11,
    "INST_LW"        : 0x12,
    "INST_LE"        : 0x13,
    "INST_GR"        : 0x14,
    "INST_GE"        : 0x15,
    "INST_EQ"        : 0x16,
    "INST_NE"        : 0x17
}


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")
