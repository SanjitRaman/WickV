#include "ast/control_flow/ast_multi_list.hpp"

void MultiList::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "MultiList Goes to emitrisc without destReg" << std::endl;
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
void MultiList::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
    std::cout << "MultiList Goes to emitrisc with destreg" << std::endl;
    context.CreateScope();
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->EmitRISC(stream, context, destReg);
    }
    context.ExitScope();
}

void MultiList::Print(std::ostream &stream) const
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


entity_type MultiList::getEntity() const
{
    return entity_type::MULTI_LIST;
}

