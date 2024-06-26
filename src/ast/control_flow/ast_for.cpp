#include "ast/control_flow/ast_for.hpp"

void ForStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    // Initialise the for loop
    start_->EmitRISC(stream, context);

    // TODO: probs can move this to where the condition is emitted
    std::string destReg = context.allocateReg(
        stream);  // TODO:Want to call this destReg? May be confusing?

    std::string startLabel = context.makeLabel("for");
    std::string conditionLabel = context.makeLabel("condition");
    std::string updateLabel = context.makeLabel("updatefor");
    std::string endLabel = context.makeLabel("endfor");
    context.createLoop(startLabel, endLabel, updateLabel);
    // Jump to the end label:
    stream << "j " << conditionLabel << std::endl;

    // Emit the loop label:
    stream << startLabel << ":" << std::endl;

    // Emit the for statement
    for_statement_->EmitRISC(stream, context);

    // Emit the increment
    stream << updateLabel << ":" << std::endl;
    if (increment_ != nullptr)
    {
        increment_->EmitRISC(stream, context);
    }

    // Emit the end label
    
    stream << conditionLabel << ":" << std::endl;

    // Emit the condition
    if (loop_condition_->getEntity() == entity_type::SEMICOLON)
    {
        stream << "addi " << destReg << ", zero, 1" << std::endl;
    }
    else
    {
        loop_condition_->EmitRISC(stream, context, destReg);
    }
    // Emit the branch
    stream << "bnez " << destReg << ", " << startLabel << std::endl;

    //  Free the register
    stream << endLabel << ":" << std::endl;
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
    if (increment_ != nullptr){
        increment_->Print(stream);
    }
    stream << ") ";
    for_statement_->Print(stream);
    stream << std::endl;
}