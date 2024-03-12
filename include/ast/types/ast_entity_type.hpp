#ifndef AST_entity_type_HPP
#define AST_entity_type_HPP

const int INT_MEM = 4;
const int RA_MEM = 4;

enum entity_type
{
    INTEGER,
    INVALID,
    FUNCTION,
    VARIABLE,
    VARIABLE_ASSIGN,
    ARRAY
    // todo add more data types
};

// MIGHT DELETE
struct function_properties
{
    std::unordered_map<std::string, entity_type>
        funct_params;         //(change : just storing identifiers) //Change to
                              //<string, param>
    entity_type return_type;  // todo
};

#endif