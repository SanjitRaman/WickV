#ifndef AST_BREAK_HPP
#define AST_BREAK_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

class Break : public Node
{
   public:
    Break(){};
    virtual ~Break(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif