#include "ast/control_flow/ast_scope.hpp"

void Scope::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "Scope Goes to emitrisc without destReg" << std::endl;
    context.CreateScope();
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->EmitRISC(stream, context);
    }
    context.ExitScope();
}
void Scope::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
    std::cout << "Scope Goes to emitrisc with destreg" << std::endl;
}

void Scope::Print(std::ostream &stream) const
{
    stream << "{" << std::endl;
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->Print(stream);
    }
    stream << "}" << std::endl;
}

entity_type Scope::getEntity() const
{
    return entity_type::SCOPE;
}

