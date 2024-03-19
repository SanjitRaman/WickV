#include "ast/control_flow/ast_jump_statement.hpp"

void ReturnStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    if (expression_ != nullptr)
    {
        //TODO: Check all return types
        //TODO: Add an else statement to check for unknown return type (just assume int case)
        if (expression_->getType(context) == data_type::_int)
        {
            // Allocate temp register
            std::string tempReturn = context.allocateReg(stream);
            expression_->EmitRISC(
                stream, context,
                tempReturn);  // store the return value in a0 register
            stream << "mv a0, " << tempReturn << std::endl;
            context.deallocateReg(tempReturn);
        }
        else if (expression_->getType(context) == data_type::_float)
        {
            // Allocate temp register
            std::string tempReturn = context.allocateFloatReg(stream);
            expression_->EmitRISC(
                stream, context,
                tempReturn);  // store the return value in a0 register
            stream << "fmv.s fa0, " << tempReturn << std::endl;
            context.deallocateFloatReg(tempReturn);
        }
        else if (expression_->getType(context) == data_type::_double){
            // Allocate temp register
            std::string tempReturn = context.allocateFloatReg(stream);
            expression_->EmitRISC(
                stream, context,
                tempReturn);  // store the return value in a0 register
            stream << "fmv.d fa0, " << tempReturn << std::endl;
            context.deallocateFloatReg(tempReturn);
        }
        else if (expression_->getType(context) == data_type::_unsigned){
            // Allocate temp register
            std::string tempReturn = context.allocateReg(stream);
            expression_->EmitRISC(
                stream, context,
                tempReturn);  // store the return value in a0 register
            stream << "mv a0, " << tempReturn << std::endl;
            context.deallocateReg(tempReturn);
        }
        else if (expression_->getType(context) == data_type::_char){
            // Allocate temp register
            std::string tempReturn = context.allocateReg(stream);
            expression_->EmitRISC(
                stream, context,
                tempReturn);  // store the return value in a0 register
            stream << "mv a0, " << tempReturn << std::endl;
            context.deallocateReg(tempReturn);
        }
    }
    // stream << "ret" << std::endl;
    // Move a0, free register
    // Free register
    stream << "beq zero, zero, " << context.getReturnLabel() << std::endl;
}
void ReturnStatement::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
}

void ReturnStatement::Print(std::ostream &stream) const
{
    stream << "return";
    if (expression_ != nullptr)
    {
        stream << " ";
        expression_->Print(stream);
    }
    stream << ";" << std::endl;
}
