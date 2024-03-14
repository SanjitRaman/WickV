#include "ast/control_flow/ast_multi_list.hpp"

void MultiList::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "MultiList Goes to emitrisc without destReg" << std::endl;
    if (declaration_list_ != nullptr)
    {
        declaration_list_->EmitRISC(stream, context);
    }
    if (statement_list_ != nullptr)
    {
        statement_list_->EmitRISC(stream, context);
    }
}
void MultiList::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
    std::cout << "MultiList Goes to emitrisc with destreg" << std::endl;
}

void MultiList::Print(std::ostream &stream) const
{
    if (declaration_list_ != nullptr)
    {
        declaration_list_->Print(stream);
    }
    if (statement_list_ != nullptr)
    {
        statement_list_->Print(stream);
    }
}
