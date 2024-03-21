#include "ast/control_flow/ast_do_while.hpp"

void DoWhileStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    //  Emit the condition

    std::cout << "Emitting while statement" << std::endl;

    // TODO: probs can move this to where the condition is emitted
    std::string destReg = context.allocateReg(
        stream);  // Want to call this destReg? May be confusing?

    std::string loopLabel = context.makeLabel("while");
    std::string updateLabel = context.makeLabel("update_while");
    std::string endLabel = context.makeLabel("end_while");
    context.createLoop(updateLabel, endLabel);

    // Emit the loop label:
    stream << loopLabel << ":" << std::endl;

    // Emit the while statement
    while_statement_->EmitRISC(stream, context);

    // Emit the update label
    stream << updateLabel << ":" << std::endl;

    // Emit the condition
    condition_->EmitRISC(stream, context, destReg);

    // Emit the branch
    stream << "bnez " << destReg << ", " << loopLabel << std::endl;
    stream << endLabel << ":" << std::endl;
    context.exitLoop();
    //  Free the register
    context.deallocateReg(destReg);
}

void DoWhileStatement::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
}

void DoWhileStatement::Print(std::ostream &stream) const
{
    stream << "do (";
    while_statement_->Print(stream);
    stream << ") while (";
    condition_->Print(stream);
    stream << ") ";
    
    stream << std::endl;
}