#ifndef AST_OPERATORS_HPP
#define AST_OPERATORS_HPP

#include "ast/ast_node.hpp"

// ---------------------- AddOperator ----------------------
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

    virtual data_type getType(Context &context) const override;
};

// ---------------------- SubtractOperator ----------------------
class SubtractOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    SubtractOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~SubtractOperator()
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

    virtual data_type getType(Context &context) const override;
};

#endif

// --------------------------- MultiplyOperator ---------------------------
class MultiplyOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    MultiplyOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~MultiplyOperator()
    {
        delete op1_;
        delete op2_;
    };
    // TODO: Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

    virtual data_type getType(Context &context) const override;
};