#ifndef AST_OPERATORS_HPP
#define AST_OPERATORS_HPP

#include "ast_node.hpp"

class AddOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    AddOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~AddOperator()
    {
        delete op1_;
        delete op2_;
    };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif