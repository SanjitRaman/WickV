#ifndef AST_IF_ELSE_STATEMENT_HPP
#define AST_IF_ELSE_STATEMENT_HPP

#include "ast_context.hpp"
#include "ast_node.hpp"

class IfElseStatement : public Node
{
   private:
    Node *condition_;
    Node *if_statement_;
    Node *else_statement_;

   public:
    IfElseStatement(Node *condition, Node *if_statement, Node *else_statement)
        : condition_(condition),
          if_statement_(if_statement),
          else_statement_(else_statement){};
    virtual ~IfElseStatement()
    {
        delete condition_;
        delete if_statement_;
        delete else_statement_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif