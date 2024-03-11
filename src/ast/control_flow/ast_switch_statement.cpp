#include "ast/control_flow/ast_switch_statement.hpp"

void SwitchStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string destReg = context.allocateReg(stream);

    std::string endLabel = context.makeLabel("endswitch");

    // Emit the expression
    expression_->EmitRISC(stream, context, destReg);

    // Emit the case list
    case_list_->EmitRISC(stream, context, destReg);

    // Free the register
    context.deallocateReg(destReg);
}

void SwitchStatement::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
}

void SwitchStatement::Print(std::ostream &stream) const
{
    stream << "switch (";
    expression_->Print(stream);
    stream << ") ";
    case_list_->Print(stream);
    stream << std::endl;
}