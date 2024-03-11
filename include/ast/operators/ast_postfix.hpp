#ifndef AST_POSTFIX_HPP
#define AST_POSTFIX_HPP

#include "ast/ast_node.hpp"

class PostfixOperator : public Node
{
   private:
    Node *primary_expression_;
    std::string op_;

   public:
    PostfixOperator(Node *primary_expression, std::string op) : primary_expression_(primary_expression), op_(op){};
    virtual ~PostfixOperator()
    {
        delete primary_expression_;
    };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};


#endif