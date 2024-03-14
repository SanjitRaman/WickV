#include "ast/control_flow/ast_for.hpp"

void ForStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    //Initialise the for loop
    start_->EmitRISC(stream, context);

    // TODO: probs can move this to where the condition is emitted
    std::string destReg = context.allocateReg(stream); //TODO:Want to call this destReg? May be confusing?

    std::string startLabel = context.makeLabel("for");
    std::string endLabel = context.makeLabel("endfor");
    std::string updateLabel = context.makeLabel("updatefor");
    context.createLoop(startLabel, endLabel, updateLabel);
    // Jump to the end label:
    stream << "j " << endLabel << std::endl;

    // Emit the loop label:
    stream << startLabel << ":" << std::endl;

    // Emit the for statement
    for_statement_->EmitRISC(stream, context);

    // Emit the increment
    stream << updateLabel << ":" << std::endl;
    if (increment_ != nullptr){
        increment_->EmitRISC(stream, context);
    }
    

    // Emit the end label
    stream << endLabel << ":" << std::endl;

    // Emit the condition
    loop_condition_->EmitRISC(stream, context, destReg);

    // Emit the branch
    stream << "bnez " << destReg << ", " << startLabel << std::endl;

    //  Free the register
    context.exitLoop();
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