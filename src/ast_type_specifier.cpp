#include "ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context) const {}
void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
}
void TypeSpecifier::Print(std::ostream &stream) const { stream << type_; }

entity_type TypeSpecifier::getType() const
{
    if (type_ == "int")
    {
        return INTEGER;
    }
}

std::string TypeSpecifier::getId() const
{
    return "type";  // The program should never enter this method
}
