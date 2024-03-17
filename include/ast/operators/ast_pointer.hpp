#ifndef AST_POINTER_HPP
#define AST_POINTER_HPP

#include "ast/ast_node.hpp"

// ---------------------- Pointer ----------------------
class Pointer : public Node
{

   public:
    Pointer(){};
    virtual ~Pointer()
    {
    };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif