#include "ast_if_else_statement.hpp"

void IfElseStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    //  Emit the condition

    std::cout << "Emitting IfElseStatement" << std::endl;

    std::string destReg = context.allocateReg(stream);

    std::string elseLabel = context.makeLabel("else");
    std::string endLabel = context.makeLabel("endif");

    condition_->EmitRISC(stream, context, destReg);
    // Emit the branch
    stream << "beqz " << destReg << ", " << elseLabel << std::endl;

    // Emit the statement
    if_statement_->EmitRISC(stream, context);

    // Emit the jump to the end
    stream << "j " << endLabel << std::endl;

    // Emit the else label
    stream << elseLabel << ":" << std::endl;

    // Emit the else statement
    else_statement_->EmitRISC(stream, context);

    // Emit the end label
    stream << endLabel << ":" << std::endl;

    //  Free the register
    context.deallocateReg(destReg);
}

void IfElseStatement::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
}
void IfElseStatement::Print(std::ostream &stream) const
{
    stream << "if (";
    condition_->Print(stream);
    stream << ") ";
    if_statement_->Print(stream);
    stream << " else ";
    else_statement_->Print(stream);
    stream << std::endl;
}