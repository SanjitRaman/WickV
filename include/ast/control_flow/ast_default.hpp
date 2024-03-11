#ifndef AST_DEFAULT_HPP
#define AST_DEFAULT_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

class DefaultStatement : public Node
{
   public:
    DefaultStatement(Node *statement)
        : statement_(statement){};

    virtual ~DefaultStatement()
    {
        delete statement_;
    }

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

   private:
    Node *statement_;
};

#endif