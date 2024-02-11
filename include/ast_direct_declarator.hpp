#ifndef AST_DIRECT_DECLARATOR_HPP
#define AST_DIRECT_DECLARATOR_HPP

#include "ast_node.hpp"

class DirectDeclarator : public Node
{
private:
    Node *identifier_;
    Node *parameter_list_;

public:
    DirectDeclarator(Node *identifier, Node *parameter_list=nullptr) : identifier_(identifier), parameter_list_(parameter_list){};
    virtual ~DirectDeclarator()
    {
        delete identifier_;
        delete parameter_list_;
    };
    virtual void EmitRISC(std::ostream &stream, Context &context) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
