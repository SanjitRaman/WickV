#ifndef AST_CASE_HPP
#define AST_CASE_HPP

#include "ast_context.hpp"
#include "ast_node.hpp"

class Case : public Node
{
   public:
    Case(Node *expression, Node *statement)
        : expression_(expression), statement_(statement){};

    virtual ~Case()
    {
        delete expression_;
        delete statement_;
    }

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

   private:
    Node *expression_;
    Node *statement_;
};

#endif