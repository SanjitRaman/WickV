#include "ast/keywords/ast_jump_statement.hpp"

void ReturnStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    if (expression_ != nullptr)
    {
        //Allocate temp register
        expression_->EmitRISC(stream, context, "a0"); // store the return value in a0 register
        
    }
    // stream << "ret" << std::endl;
    //Move a0, free register
    //Free register
    stream << "beq zero, zero, " << context.getReturnLabel() << std::endl;
}
void ReturnStatement::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
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
