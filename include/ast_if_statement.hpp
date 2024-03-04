#ifndef AST_IF_STATEMENT_HPP
#define AST_IF_STATEMENT_HPP

#include <iostream>
#include <vector>

#include "ast_context.hpp"
#include "ast_node.hpp"

class IfStatement : public Node
{
   public:
    IfStatement(Node *condition, Node *if_statement,
                std::vector<Node *> &else_if_statements, Node *else_statement)
        : condition_(condition),
          if_statement_(if_statement),
          else_if_statements_(else_if_statements),
          else_statement_(else_statement)
    {
    }

    virtual ~IfStatement() {}

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;

    // TODO: for turnary operator?
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

   private:
    Node *condition_;
    Node *if_statement_;
    std::vector<Node *> else_if_statements_;
    Node *else_statement_;
};

#endif