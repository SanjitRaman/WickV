#include "ast_declaration.hpp"

void Declaration::EmitRISC(std::ostream &stream, Context &context) const
{
    for (auto node : init_declaration_list_->getNodes())
    {
        if (node == nullptr)
        {
            continue;
        }
        context.createBinding(node->getId(), declaration_specifiers_->getType());
        node->EmitRISC(stream, context);
    }
}

void Declaration::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}
void Declaration::Print(std::ostream &stream) const
{
    //TODO: Implement
}

data_type Declaration::getType() const
{
    return declaration_specifiers_->getType();
}