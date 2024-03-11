#include "ast/control_flow/ast_default.hpp"


void DefaultStatement::EmitRISC(std::ostream &stream, Context &context) const
{
}

void DefaultStatement::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
}

void DefaultStatement::Print(std::ostream &stream) const { 
    stream << "{}"; 
}
