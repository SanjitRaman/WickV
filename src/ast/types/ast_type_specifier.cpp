#include "ast/types/ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context) const {}
void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
}
void TypeSpecifier::Print(std::ostream &stream) const { stream << type_; }

// This shouldn't be used ever.
entity_type TypeSpecifier::getEntity() const
{
    std::cout << "TypeSpecifier::getEntity() should not be used anymore."
              << std::endl;
    // if (type_ == "int")
    // {
    //     return INTEGER;
    // }
    // else if (type_ == "float")
    // {
    //     return FLOAT_VALUE;
    // }
    return INVALID;  // TODO: Add more types
}

std::string TypeSpecifier::getId() const
{
    return "type";  // The program should never enter this method
}

data_type TypeSpecifier::getType() const
{
    if (type_ == "int")
    {
        return data_type::_int;
    }
    else if (type_ == "float")
    {
        return data_type::_float;
    }
    else if (type_ == "double")
    {
        return data_type::_double;
    }
    else if (type_ == "char")
    {
        return data_type::_char;
    }
    else if (type_ == "unsigned")
    {
        return data_type::_unsigned;
    }
    else if (type_ == "void")
    {
        return data_type::_void;
    }
    return _INVALID;  // TODO: Add more types
}

data_type TypeSpecifier::getType(Context &context) const
{
    if (type_ == "int")
    {
        return data_type::_int;
    }
    else if (type_ == "float")
    {
        return data_type::_float;
    }
    else if (type_ == "double")
    {
        return data_type::_double;
    }
    else if (type_ == "char")
    {
        return data_type::_char;
    }
    else if (type_ == "unsigned")
    {
        return data_type::_unsigned;
    }
    return _INVALID;  // TODO: Add more types
}