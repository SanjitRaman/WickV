#ifndef AST_CONSTANT_HPP
#define AST_CONSTANT_HPP

#include "ast_node.hpp"

class IntConstant : public Node
{
private:
    int value_;

public:
    IntConstant(int value) : value_(value) {}

    virtual void EmitRISC(std::ostream &stream, Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
