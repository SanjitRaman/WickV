#include "ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context) const {}

void TypeSpecifier::Print(std::ostream &stream) const
{
    stream << type_;
}

data_type TypeSpecifier::getType() const {
    if (type_ == "int"){
        return INTEGER;
    }
}

std::string TypeSpecifier::getId() const {
    return "type"; //The program should never enter this method
}
