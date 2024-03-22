#include "ast/control_flow/ast_semicolon.hpp"


void Semicolon::EmitRISC(std::ostream &stream, Context &context) const
{
}

void Semicolon::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
}

void Semicolon::Print(std::ostream &stream) const { 
    stream << ";";  //TODO: Check if new line is needed
}

entity_type Semicolon::getEntity() const
{
    return entity_type::SEMICOLON;
}
