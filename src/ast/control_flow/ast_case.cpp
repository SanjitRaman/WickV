#include "ast/control_flow/ast_case.hpp"


void CaseStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    
    
}

void CaseStatement::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    std::cout << "I come to Case" << std::endl;
    std::string endCaseLabel = context.makeLabel("end_case");

    std::string expression_reg = context.allocateReg(stream);
    expression_->EmitRISC(stream, context, expression_reg);
    stream << "bne " << destReg << ", " << expression_reg << ", " << endCaseLabel << std::endl;
    context.deallocateReg(expression_reg);
    
    statement_->EmitRISC(stream, context);
    stream << "j " << context.getSwitchLabel() << std::endl;
    stream << endCaseLabel << ":" << std::endl;
}

void CaseStatement::Print(std::ostream &stream) const { 
    stream << "case ";
    expression_->Print(stream);
    stream << ": ";
    statement_->Print(stream);
    stream << std::endl; 
}
