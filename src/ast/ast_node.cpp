#include "ast/ast_node.hpp"

Node::~Node()
{
    for (auto branch : branches_)
    {
        delete branch;
    }
}
entity_type Node::getType() const
{
    return INVALID;  // Shouldn't go here
}

std::string Node::getId() const
{
    return "ERROR";  // Shouldn't go here
}

void NodeList::PushBack(Node *item) { nodes_.push_back(item); }

void NodeList::EmitRISC(std::ostream &stream, Context &context) const
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
void NodeList::EmitRISC(std::ostream &stream, Context &context,
                        std::string destReg) const
{
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->EmitRISC(stream, context, destReg);
    }
}

void NodeList::Print(std::ostream &stream) const
{
    stream << "{\n" << std::endl;
    for (auto node : nodes_)
    {
        if (node == nullptr)
        {
            continue;
        }
        node->Print(stream);
    }
    stream << "}\n" << std::endl;
}
const std::vector<Node *> &NodeList::getNodes() const { return nodes_; }