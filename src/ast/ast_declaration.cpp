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
        if (node->getEntity() == entity_type::VARIABLE_ASSIGN)
        {
            std::cout << "VARASSIGN" << std::endl;
            context.createBinding(node->getId(),
                                  declaration_specifiers_->getType(), false);
            node->EmitRISC(stream, context);
        }
        else if (node->getEntity() == entity_type::POINTER_ASSIGN)
        {
            std::cout << "POINTERASSIGN" << std::endl;
            context.createBinding(node->getId(),
                                  declaration_specifiers_->getType(), true);
            node->EmitRISC(stream, context);
        }
        // check if it is a struct type before it checks for member variables.
        else if (declaration_specifiers_->getEntity() ==
                 entity_type::STRUCT_DEC)
        {
            std::cout << "STRUCT_DEC" << std::endl;
            context.createStructBindings(declaration_specifiers_->getId(),
                                         node->getId());
        }
        else if (node->getEntity() == entity_type::VARIABLE)
        {
            std::cout << "VAR" << std::endl;
            context.createBinding(node->getId(),
                                  declaration_specifiers_->getType(), false);
        }
        else if (node->getEntity() == entity_type::ARRAY)
        {
            std::cout << "ARRAY" << std::endl;
            // Create binding here for array
            context.createBinding(node->getId(),
                                  declaration_specifiers_->getType(), false);
            // Call emit risc on array declarator
            node->EmitRISC(stream, context);
        }
        else if (node->getEntity() == entity_type::POINTER)
        {
            std::cout << "POINTER" << std::endl;

            if (declaration_specifiers_->getType() == data_type::_char)
            {
                context.createBinding(node->getId(),
                                      declaration_specifiers_->getType(),
                                      true);  // TODO check that passing
            }
            else
            {
                // Create binding here for pointer
                context.createBinding(node->getId(),
                                      declaration_specifiers_->getType(), true);
                // Do we need to specify that this is a pointer in context?
                // Call emit risc on pointer declarator
                //  node->EmitRISC(stream, context);
            }
        }
        else if (node->getEntity() == entity_type::FUNCTION)
        {
            std::cout << "FUNCTION" << std::endl;
            context.setFunctionReturnType(node->getId(),
                                          declaration_specifiers_->getType());
        }
        // TODO: Add pointer entity type here
    }
}

void Declaration::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
}
void Declaration::Print(std::ostream &stream) const
{
    // TODO: Implement
}

entity_type Declaration::getEntity() const
{
    return declaration_specifiers_->getEntity();
}