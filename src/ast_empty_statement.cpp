#include "ast_empty_statement.hpp"


void EmptyStatement::EmitRISC(std::ostream &stream, Context &context) const
{
}

void EmptyStatement::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
}

void EmptyStatement::Print(std::ostream &stream) const { 
    stream << "{}"; 
}
