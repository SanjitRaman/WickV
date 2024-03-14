#include "ast/operators/ast_ternary.hpp"

// ---------------------------- Ternary ----------------------------

void Ternary::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    std::string false_label = context.makeLabel("false_condition");
    std::string end_label = context.makeLabel("end_ternary");
    std::string condReg = context.allocateReg(stream);
    condition_->EmitRISC(stream, context, condReg);
    stream << "beq " << condReg << ", zero, " << false_label << std::endl;
    true_expression_->EmitRISC(stream, context, destReg);
    stream << "j " << end_label << std::endl;
    stream << false_label << ":" << std::endl;
    false_expression_->EmitRISC(stream, context, destReg);
    stream << end_label << ":" << std::endl;
    context.deallocateReg(condReg);
}

void Ternary::EmitRISC(std::ostream &stream, Context &context) const {}

void Ternary::Print(std::ostream &stream) const
{
    stream << "(";
    condition_->Print(stream);
    stream << " ? ";
    true_expression_->Print(stream);
    stream << " : ";
    false_expression_->Print(stream);
    stream << ")";
    
}