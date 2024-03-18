#include "ast/types/ast_char_literal.hpp"
void CharLiteral::EmitRISC(std::ostream &stream, Context &context) const {}

void CharLiteral::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
    stream << "li " << destReg << ", " << char_literal_ << std::endl;
}
// Try not to use below method
entity_type CharLiteral::getEntity() const
{
    // return type_;
    return entity_type::CHAR_DEFINITION;
}

data_type CharLiteral::getType(Context &context) const
{
    return data_type::_char;
}

data_type CharLiteral::getType() const
{
    // shouldn't go here
    return data_type::_char;
}

std::string CharLiteral::getId() const { return char_literal_; }

void CharLiteral::Print(std::ostream &stream) const
{
    stream << char_literal_;
};
