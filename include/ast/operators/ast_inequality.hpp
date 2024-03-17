#ifndef AST_INEQUALITY_STATEMENT_HPP
#define AST_INEQUALITY_STATEMENT_HPP

#include "ast/ast_node.hpp"

class GreaterThan : public Node
{
   private:
    Node *left_;
    Node *right_;

   public:
    GreaterThan(Node *left, Node *right) : left_(left), right_(right){};
    virtual ~GreaterThan()
    {
        delete left_;
        delete right_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

class LessThan : public Node
{
   private:
    Node *left_;
    Node *right_;

   public:
    LessThan(Node *left, Node *right) : left_(left), right_(right){};
    virtual ~LessThan()
    {
        delete left_;
        delete right_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

class LessThanEqual : public Node
{
   private:
    Node *left_;
    Node *right_;

   public:
    LessThanEqual(Node *left, Node *right) : left_(left), right_(right){};
    virtual ~LessThanEqual()
    {
        delete left_;
        delete right_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

class GreaterThanEqual : public Node
{
   private:
    Node *left_;
    Node *right_;

   public:
    GreaterThanEqual(Node *left, Node *right) : left_(left), right_(right){};
    virtual ~GreaterThanEqual()
    {
        delete left_;
        delete right_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};



#endif