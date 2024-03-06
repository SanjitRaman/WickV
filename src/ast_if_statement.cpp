#include "ast_if_statement.hpp"

void IfStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    //  Emit the condition

    std::cout << "Emitting if statement" << std::endl;

    std::string destReg = context.allocateReg(stream);

    std::string endLabel = context.makeLabel("endif");

    condition_->EmitRISC(stream, context, destReg);
    // Emit the branch
    stream << "beqz " << destReg << ", " << endLabel << std::endl;

    // Emit the statement
    if_statement_->EmitRISC(stream, context);

    // Emit the end label
    stream << endLabel << ":" << std::endl;

    //  Free the register
    context.deallocateReg(destReg);
}

void IfStatement::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
}

void IfStatement::Print(std::ostream &stream) const
{
    stream << "if (";
    condition_->Print(stream);
    stream << ") ";
    if_statement_->Print(stream);
    stream << std::endl;
}