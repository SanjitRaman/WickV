#ifndef AST_DO_WHILE_STATEMENT_HPP
#define AST_DO_WHILE_STATEMENT_HPP



#include "ast/ast_node.hpp"

class DoWhileStatement : public Node
{
   private:
    Node *condition_;
    Node *while_statement_;

   public:
    DoWhileStatement(Node *while_statement, Node *condition)
        : condition_(condition), while_statement_(while_statement){};
    virtual ~DoWhileStatement()
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