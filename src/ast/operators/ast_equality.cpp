#include "ast/operators/ast_equality.hpp"

// ---------------------- Equality ----------------------

void Equality::EmitRISC(std::ostream &stream, Context &context,
                        std::string destReg) const
{
    std::string op1_reg = context.allocateReg(stream);
    equality_expression_->EmitRISC(stream, context, op1_reg);
    stream << "mv " << destReg << ", " << op1_reg << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    relational_expression_->EmitRISC(stream, context, op2_reg);
    stream << "xor " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    stream << "seqz " << destReg << ", " << destReg << std::endl;
}

void Equality::EmitRISC(std::ostream &stream, Context &context) const {}

void Equality::Print(std::ostream &stream) const {}

data_type Equality::getType(Context &context) const { return data_type::_int; }


// ---------------------- NotEqual ----------------------

void NotEqual::EmitRISC(std::ostream &stream, Context &context,
                        std::string destReg) const
{
    std::string op1_reg = context.allocateReg(stream);
    equality_expression_->EmitRISC(stream, context, op1_reg);
    stream << "mv " << destReg << ", " << op1_reg << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    relational_expression_->EmitRISC(stream, context, op2_reg);
    stream << "xor " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    stream << "snez " << destReg << ", " << destReg << std::endl;
}

void NotEqual::EmitRISC(std::ostream &stream, Context &context) const {}

void NotEqual::Print(std::ostream &stream) const {}

data_type NotEqual::getType(Context &context) const { return data_type::_int; }