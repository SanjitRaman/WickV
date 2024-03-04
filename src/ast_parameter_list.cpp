#include "ast_parameter_list.hpp"

void ParameterList::EmitRISC(std::ostream &stream, Context &context) const
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
void ParameterList::Print(std::ostream &stream) const
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