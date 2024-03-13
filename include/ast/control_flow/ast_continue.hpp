#ifndef AST_CONTINUE_HPP
#define AST_CONTINUE_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

class Continue : public Node
{
   public:
    Continue(){};
    virtual ~Continue(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif