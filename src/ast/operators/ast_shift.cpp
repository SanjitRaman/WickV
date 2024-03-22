#include "ast/operators/ast_shift.hpp"

void LeftShift::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
    shift_expression_->EmitRISC(stream, context, destReg);
    std::string add_reg = context.allocateReg(stream);
    additive_expression_->EmitRISC(stream, context, add_reg);
    stream << "sll " << destReg << ", " << destReg << ", " << add_reg << std::endl;
    context.deallocateReg(add_reg);

}

void LeftShift::EmitRISC(std::ostream &stream, Context &context) const
{
}

void LeftShift::Print(std::ostream &stream) const
{
    stream << "(";
    shift_expression_->Print(stream);
    stream << " << ";
    additive_expression_->Print(stream);
    stream << ")";
}

data_type LeftShift::getType(Context &context) const
{
    return data_type::_int; //TODO: check that it is always int (should be)
}

// ---------------------------- RightShift ----------------------------

void RightShift::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
    shift_expression_->EmitRISC(stream, context, destReg);
    std::string add_reg = context.allocateReg(stream);
    additive_expression_->EmitRISC(stream, context, add_reg);
    stream << "srl " << destReg << ", " << destReg << ", " << add_reg << std::endl;
    context.deallocateReg(add_reg);
}

void RightShift::EmitRISC(std::ostream &stream, Context &context) const
{
}

void RightShift::Print(std::ostream &stream) const
{
    stream << "(";
    shift_expression_->Print(stream);
    stream << " >> ";
    additive_expression_->Print(stream);
    stream << ")";
}

data_type RightShift::getType(Context &context) const
{
    return data_type::_int; //TODO: check that it is always int (should be)
}