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

// --------------------------- DivideOperator ----------------------------
class DivideOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    DivideOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~DivideOperator()
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

// -------------------------- BitwiseAndOperator --------------------------
class BitwiseAndOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    BitwiseAndOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~BitwiseAndOperator()
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

// -------------------------- BitwiseOrOperator ---------------------------
class BitwiseOrOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    BitwiseOrOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~BitwiseOrOperator()
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

// -------------------------- BitwiseXorOperator --------------------------
class BitwiseXorOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    BitwiseXorOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~BitwiseXorOperator()
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

// -------------------------- LogicalAndOperator --------------------------
class LogicalAndOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    LogicalAndOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~LogicalAndOperator()
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

// -------------------------- LogicalOrOperator --------------------------
class LogicalOrOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    LogicalOrOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~LogicalOrOperator()
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

// -------------------------- ModulusOperator --------------------------

class ModulusOperator : public Node
{
   private:
    Node *op1_;
    Node *op2_;

   public:
    ModulusOperator(Node *op1, Node *op2) : op1_(op1), op2_(op2){};
    virtual ~ModulusOperator()
    {
        delete op1_;
        delete op2_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

    virtual data_type getType(Context &context) const override;
};