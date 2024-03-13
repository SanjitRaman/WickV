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
    std::cout << "I come to expression_" << std::endl;
    expression_->EmitRISC(stream, context, expression_reg);
    std::cout << "I leave to expression_" << std::endl;
    stream << "bne " << destReg << ", " << expression_reg << ", " << endCaseLabel << std::endl;
    
    context.deallocateReg(expression_reg);
    
    // getNextCaseLabel from previous emitrisc and put here
    std::string currentCaseLabel = context.getCaseLabel();
    stream << currentCaseLabel << ":" << std::endl;
    std::cout << "I come to statement_" << std::endl;
    statement_->EmitRISC(stream, context);
    std::cout << "I leave to statement_" << std::endl;
    context.setCaseLabel();
    std::string nextCaseLabel = context.getCaseLabel();
    stream << "j " << nextCaseLabel << std::endl;
    //Branch to nextCaseLabel and set it in context

    stream << endCaseLabel << ":" << std::endl; //
}

void CaseStatement::Print(std::ostream &stream) const { 
    stream << "case ";
    expression_->Print(stream);
    stream << ": ";
    statement_->Print(stream);
    stream << std::endl; 
}
