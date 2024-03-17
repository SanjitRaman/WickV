#include "ast/functions/ast_function_call.hpp"

void FunctionCall::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "goes to 2 params" << std::endl;
    // For up to 8 arguments
    if (argument_expression_list_ != nullptr)
    {
        int i = 0;
        for (auto arg : argument_expression_list_->getNodes())
        {
            std::string argReg = "a" + std::to_string(i);
            arg->EmitRISC(stream, context, argReg);
            i++;
        }
    }

    // TODO : Why there is a nop in compiler explorer (GodBolt)
    std::cout << postfix_expression_->getId()
              << std::endl;  // Check what this outputs

    // stream << "sw x5, 0(sp)" << std::endl;
    // stream << "sw x7, 4(sp)" << std::endl;
    context.saveRegs(stream);
    stream << "call " << postfix_expression_->getId() << std::endl;
    stream << "nop" << std::endl;
    context.restoreRegs(stream);
    // stream << "lw x5, 0(sp)" << std::endl;
    // stream << "lw x7, 4(sp)" << std::endl;
    // TODO: deallocate memory allocated to ra_offset
}

void FunctionCall::EmitRISC(std::ostream &stream, Context &context,
                            std::string destReg) const
{
    // May need to use this to move to destReg (but it is generally always in
    // a0)
    std::cout << "FUNCT CALL" << std::endl;
    this->EmitRISC(stream, context);
    stream << "mv " << destReg << ", a0"
           << std::endl;  // May not need to move into destReg as return value
                          // is always in a0
}
void FunctionCall::Print(std::ostream &stream) const
{
    postfix_expression_->Print(stream);
    stream << "(";
    // TODO: FIX extra ,
    if (argument_expression_list_ != nullptr)
    {
        for (auto node : argument_expression_list_->getNodes())
        {
            if (node == nullptr)
            {
                continue;
            }
            node->Print(stream);
            stream << ", ";
        }
    }
    stream << ")" << std::endl;
}

data_type FunctionCall::getType(Context &context) const
{
    std::cout << context.getFunctionReturnType(postfix_expression_->getId())
              << std::endl;
    return context.getFunctionReturnType(postfix_expression_->getId());
}