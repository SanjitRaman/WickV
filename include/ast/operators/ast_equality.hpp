#ifndef AST_EQUALITY_HPP
#define AST_EQUALITY_HPP

#include "ast/ast_node.hpp"

class Equality : public Node
{
   private:
    Node *equality_expression_;
    Node *relational_expression_;

   public:
    Equality(Node *equality_expression, Node* relational_expression)
        : equality_expression_(equality_expression),
          relational_expression_(relational_expression)
    {
    }
    virtual ~Equality()
    {
        delete equality_expression_;
        delete relational_expression_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
