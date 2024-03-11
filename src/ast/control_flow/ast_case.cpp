#include "ast/control_flow/ast_case.hpp"


void CaseStatement::EmitRISC(std::ostream &stream, Context &context) const
{
}

void CaseStatement::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
}

void CaseStatement::Print(std::ostream &stream) const { 
    stream << "{}"; 
}
