#include "ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context) const {}

void TypeSpecifier::Print(std::ostream &stream) const
{
    stream << type_;
}

std::string TypeSpecifier::getType() const {
    return type_;
}
