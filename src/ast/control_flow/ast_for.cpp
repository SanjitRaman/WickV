#include "ast/control_flow/ast_for.hpp"

void ForStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    //Initialise the for loop
    start_->EmitRISC(stream, context);

    // TODO: probs can move this to where the condition is emitted
    std::string destReg = context.allocateReg(stream); //Want to call this destReg? May be confusing?

    std::string loopLabel = context.makeLabel("for");
    std::string endLabel = context.makeLabel("endfor");

    // Jump to the end label:
    stream << "j " << endLabel << std::endl;

    // Emit the loop label:
    stream << loopLabel << ":" << std::endl;

    // Emit the while statement
    for_statement_->EmitRISC(stream, context);

    increment_->EmitRISC(stream, context);

    // Emit the end label
    stream << endLabel << ":" << std::endl;

    // Emit the condition
    loop_condition_->EmitRISC(stream, context, destReg);

    // Emit the branch
    stream << "bnez " << destReg << ", " << loopLabel << std::endl;

    //  Free the register
    context.deallocateReg(destReg); 
}

void ForStatement::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
}

void ForStatement::Print(std::ostream &stream) const
{
    stream << "for (";
    start_->Print(stream);
    stream << "; ";
    loop_condition_->Print(stream);
    stream << "; ";
    increment_->Print(stream);
    stream << ") ";
    for_statement_->Print(stream);
    stream << std::endl;
}