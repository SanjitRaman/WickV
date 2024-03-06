#ifndef AST_EMPTY_STATEMENT_HPP
#define AST_EMPTY_STATEMENT_HPP

#include "ast_context.hpp"
#include "ast_node.hpp"

class EmptyStatement : public Node
{
   public:
    EmptyStatement(){};
    virtual ~EmptyStatement(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif