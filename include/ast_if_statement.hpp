#ifndef AST_IF_STATEMENT_HPP
#define AST_IF_STATEMENT_HPP


#include "ast_context.hpp"
#include "ast_node.hpp"

class IfStatement : public Node
{
   private:
    Node *condition_;
    Node *if_statement_;

   public:
    IfStatement(Node *condition, Node *if_statement)
        : condition_(condition), if_statement_(if_statement){};
    virtual ~IfStatement()
    {
        delete condition_;
        delete if_statement_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif