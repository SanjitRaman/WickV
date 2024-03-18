#include "ast/types/ast_string_literal.hpp"
void StringLiteral::EmitRISC(std::ostream &stream, Context &context) const {}

void StringLiteral::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
    std::string branch_name = context.makeLabel("string");
    context.addStringHeader(branch_name, string_literal_);

    stream << "lui " << destReg << ", %hi(" << branch_name << ")" << std::endl;
    stream << "addi " << destReg << ", " << destReg << ", %lo(" << branch_name
           << ")" << std::endl;
}
// Try not to use below method
entity_type StringLiteral::getEntity() const
{
    // return type_;
    return entity_type::STRING_DEFINTION;
}

data_type StringLiteral::getType(Context &context) const
{
    return data_type::_char;
}

data_type StringLiteral::getType() const
{
    // shouldn't go here
    return data_type::_char;
}

std::string StringLiteral::getId() const { return string_literal_; }

void StringLiteral::Print(std::ostream &stream) const
{
    stream << string_literal_;
};
