#ifndef AST_WHILE_STATEMENT_HPP
#define AST_WHILE_STATEMENT_HPP

#include "ast/ast_node.hpp"

class WhileStatement : public Node
{
   private:
    Node *condition_;
    Node *while_statement_;

   public:
    WhileStatement(Node *condition, Node *while_statement)
        : condition_(condition), while_statement_(while_statement){};
    virtual ~WhileStatement()
    {
        delete condition_;
        delete while_statement_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif