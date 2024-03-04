#include "ast/control_flow/ast_multi_list.hpp"

void MultiList::EmitRISC(std::ostream &stream, Context &context) const
{
    if (declaration_list_ != nullptr)
    {
        declaration_list_->EmitRISC(stream, context);
    }
    if (statement_list_ != nullptr)
    {
        statement_list_->EmitRISC(stream, context);
    }
}
void MultiList::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

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
