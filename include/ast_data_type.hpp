#ifndef AST_DATA_TYPE_HPP
#define AST_DATA_TYPE_HPP
enum data_type {
    INTEGER,
    INVALID
    // todo add more data types
};

//MIGHT DELETE
struct function_properties {
    std::unordered_map<std::string, data_type> funct_params; //(change : just storing identifiers)
    data_type return_type; // todo
};



#endif