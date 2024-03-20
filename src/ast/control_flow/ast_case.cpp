#include "ast/control_flow/ast_case.hpp"

void CaseStatement::EmitRISC(std::ostream &stream, Context &context) const {}

void CaseStatement::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
    if (context.getCaseCond()){
        std::string case_label = context.setCaseLabel();
        std::string cond_reg = context.allocateReg(stream);
        expression_->EmitRISC(stream, context, cond_reg);
        stream << "beq " << cond_reg << ", " << destReg << ", " << case_label << std::endl;
        context.deallocateReg(cond_reg);
    }
    else{
        std::string case_label = context.getCaseLabel();
        stream << case_label << ":" << std::endl;
        statement_->EmitRISC(stream, context);
    }
}

void CaseStatement::Print(std::ostream &stream) const
{
    stream << "case ";
    expression_->Print(stream);
    stream << ": ";
    statement_->Print(stream);
    stream << std::endl;
}

entity_type CaseStatement::getEntity() const
{
    return entity_type::CASE;
}