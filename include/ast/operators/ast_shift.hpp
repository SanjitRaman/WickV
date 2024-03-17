#ifndef AST_SHIFT_HPP
#define AST_SHIFT_HPP

#include "ast/ast_node.hpp"

class LeftShift : public Node
{
   private:
    Node *shift_expression_;
    Node *additive_expression_;

   public:
    LeftShift(Node *shift_expression, Node *additive_expression)
        : shift_expression_(shift_expression), additive_expression_(additive_expression){};
    virtual ~LeftShift() { 
        delete shift_expression_;
        delete additive_expression_;
    };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

class RightShift : public Node
{
   private:
    Node *shift_expression_;
    Node *additive_expression_;

   public:
    RightShift(Node *shift_expression, Node *additive_expression)
        : shift_expression_(shift_expression), additive_expression_(additive_expression){};
    virtual ~RightShift() { 
        delete shift_expression_;
        delete additive_expression_;
        };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

#endif