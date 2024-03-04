#include "ast/ast_declaration.hpp"

void Declaration::EmitRISC(std::ostream &stream, Context &context) const
{
    for (auto node : init_declaration_list_->getNodes())
    {
        if (node == nullptr)
        {
            continue;
        }
        std::cout << "DECLARATION" << std::endl;
        if (node->getType() == entity_type::VARIABLE_ASSIGN){
            std::cout << "VARASSIGN" << std::endl;
            context.createBinding(node->getId(), declaration_specifiers_->getType());
            node->EmitRISC(stream, context);
        }
        else if (node->getType() == entity_type::VARIABLE){
            std::cout << "VAR" << std::endl;
            context.createBinding(node->getId(), declaration_specifiers_->getType());
        }
        
    }
}

void Declaration::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}
void Declaration::Print(std::ostream &stream) const
{
    //TODO: Implement
}

entity_type Declaration::getType() const
{
    return declaration_specifiers_->getType();
}