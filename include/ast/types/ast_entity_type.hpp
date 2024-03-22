#ifndef AST_ENTITY_TYPE_HPP
#define AST_ENTITY_TYPE_HPP

const int INT_MEM = 4;
const int RA_MEM = 4;
const int DOUBLE_MEM = 8;
const int FLOAT_MEM = 4;
const int CHAR_MEM = 1;


enum entity_type
{
    INVALID,
    FUNCTION,
    VARIABLE,
    VARIABLE_ASSIGN,
    POINTER_ASSIGN,
    ARRAY,
    ENUM_SPECIFIER,
    ENUMERATOR,
    POINTER,
    UNARY,
    STRUCT_DEC,
    STRUCT_SPECIFIER,
    SIZE_OF,
    STRING_DEFINTION,
    CHAR_DEFINITION,
    TYPEDEF_IDENTIFIER,
    TYPEDEF_DEC,
    CASE_STATEMENT,
    DEFAULT_STATEMENT,
    SCOPE,
    MULTI_LIST,
    SWITCH_STATEMENT,
    SEMICOLON,
    POINTER_DEREFERENCE,
    POINTER_ADDRESS
};

enum data_type
{
    _INVALID,
    _int,
    _void,
    _unsigned,
    _char,
    _float,
    _double
};


#endif