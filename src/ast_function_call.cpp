#include "ast_function_call.hpp"

void FunctionCall::EmitRISC(std::ostream &stream, Context &context) const
{
    int i = 0;
    //For up to 8 arguments
    for (auto arg : argument_expression_list_->getNodes())
    {
        
        std::string argReg = "a" + std::to_string(i);
        arg->EmitRISC(stream, context, argReg);
        i++;
    }
    //TODO : Why there is a nop in compiler explorer (GodBolt)
    std::cout << postfix_expression_->getId() << std::endl;
    stream << "jal " << postfix_expression_->getId() << std::endl;
}

void FunctionCall::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{
    //May need to use this to move to destReg (but it is generally always in a0)
}
void FunctionCall::Print(std::ostream &stream) const
{
    postfix_expression_->Print(stream);
    stream << "(";
    if (argument_expression_list_ != nullptr)
    {
        
        argument_expression_list_->Print(stream);
        
    }
    stream << ")" << std::endl;
}
