#include "ast_init_declarator_list.hpp"

void InitDeclaratorList::EmitRISC(std::ostream &stream, Context &context) const
{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->EmitRISC(stream, context);
    }
}

void InitDeclaratorList::EmitRISC(std::ostream &stream, Context &context,
                                  std::string destReg) const
{
}
void InitDeclaratorList::Print(std::ostream &stream) const
{
    int n = nodes_.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nodes_[i] == nullptr)
        {
            continue;
        }
        nodes_[i]->Print(stream);
        stream << ", ";
    }

    nodes_[n - 1]->Print(stream);
}
