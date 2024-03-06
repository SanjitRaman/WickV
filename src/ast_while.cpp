#include "ast_while.hpp"

void WhileStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    //  Emit the condition

    std::cout << "Emitting while statement" << std::endl;

    // TODO: probs can move this to where the condition is emitted
    std::string destReg = context.allocateReg(stream); //Want to call this destReg? May be confusing?

    std::string loopLabel = context.makeLabel("while");
    std::string endLabel = context.makeLabel("endwhile");

    // Jump to the end label:
    stream << "j " << endLabel << std::endl;

    // Emit the loop label:
    stream << loopLabel << ":" << std::endl;

    // Emit the while statement
    while_statement_->EmitRISC(stream, context);

    // Emit the end label
    stream << endLabel << ":" << std::endl;

    // Emit the condition
    condition_->EmitRISC(stream, context, destReg);

    // Emit the branch
    stream << "bnez " << destReg << ", " << loopLabel << std::endl;

    //  Free the register
    context.deallocateReg(destReg);
}

void WhileStatement::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
}

void WhileStatement::Print(std::ostream &stream) const
{
    stream << "while (";
    condition_->Print(stream);
    stream << ") ";
    while_statement_->Print(stream);
    stream << std::endl;
}