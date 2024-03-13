#ifndef AST_SEMICOLON_HPP
#define AST_SEMICOLON_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

class Semicolon : public Node
{
   public:
    Semicolon(){};
    virtual ~Semicolon(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif