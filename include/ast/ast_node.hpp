#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>
#include <vector>

#include "ast/ast_context.hpp"

class Node
{
   protected:
    std::vector<Node *> branches_;

   public:
    Node(){};
    virtual ~Node();
    virtual void EmitRISC(std::ostream &stream, Context &context) const = 0;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const = 0;
    virtual void Print(std::ostream &stream) const = 0;
    virtual entity_type getType() const;
    virtual std::string getId() const;
};

// Represents a list of nodes.
class NodeList : public Node
{
   protected:
    std::vector<Node *> nodes_;

   public:
    NodeList(Node *first_node) : nodes_({first_node}) {}

    ~NodeList()
    {
        for (auto node : nodes_)
        {
            delete node;
        }
    }

    void PushBack(Node *item);
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    const std::vector<Node *> &getNodes() const;
};

#endif
