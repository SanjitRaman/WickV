#ifndef AST_CONSTANTS_HPP
#define AST_CONSTANTS_HPP

#include "ast/ast_node.hpp"

union FloatConversion
{
    int i; //Doesn't need to be unsigned?
    float f;
};

class IntConstant : public Node
{
   private:
    int value_;

   public:
    IntConstant(int value) : value_(value) {}

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
    virtual data_type getType() const override;
    int getValue()
        const override;  // Can define a union / struct for this return type and
                         // the relevant value is accessed?
    virtual std::string getId() const override;
};

class FloatConstant : public Node
{
   private:
    float value_;

   public:
    FloatConstant(float value) : value_(value) {}

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
    virtual data_type getType() const override;
    // float getValue() const override;
    int getValue()
        const override;  // TODO: Implement a float getValue in node and here
    virtual std::string getId() const override;
};

#endif
