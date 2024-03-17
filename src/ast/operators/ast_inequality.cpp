#include "ast/operators/ast_inequality.hpp"

// -------------------------- GreaterThan --------------------------

void GreaterThan::EmitRISC(std::ostream &stream, Context &context) const {}

void GreaterThan::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    std::string leftReg = context.allocateReg(stream);
    
    left_->EmitRISC(stream, context, leftReg);
    stream << "mv " << destReg << ", " << leftReg << std::endl;
    context.deallocateReg(leftReg);
    std::string rightReg = context.allocateReg(stream);
    right_->EmitRISC(stream, context, rightReg);
    stream << "sgt " << destReg << ", " << destReg << ", " << rightReg
           << std::endl;
    context.deallocateReg(rightReg);
}

void GreaterThan::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " > ";
    right_->Print(stream);
}

data_type GreaterThan::getType(Context &context) const
{
    return data_type::_int;
}

// -------------------------- LessThan --------------------------

void LessThan::EmitRISC(std::ostream &stream, Context &context) const {}

void LessThan::EmitRISC(std::ostream &stream, Context &context,
                        std::string destReg) const
{
    // Change to reg spill
    //TODO: Do we need to allocate a float reg here sometimes?
    std::string leftReg = context.allocateReg(stream);
    
    left_->EmitRISC(stream, context, leftReg);
    stream << "mv " << destReg << ", " << leftReg << std::endl;
    context.deallocateReg(leftReg);
    std::string rightReg = context.allocateReg(stream);
    right_->EmitRISC(stream, context, rightReg);
    stream << "slt " << destReg << ", " << destReg << ", " << rightReg
           << std::endl;
    context.deallocateReg(rightReg);
}

void LessThan::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " < ";
    right_->Print(stream);
}

data_type LessThan::getType(Context &context) const { return data_type::_int; }

// -------------------------- LessThanEqual --------------------------

void LessThanEqual::EmitRISC(std::ostream &stream, Context &context) const {}

void LessThanEqual::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
    // Change to reg spill
    std::string leftReg = context.allocateReg(stream);
    left_->EmitRISC(stream, context, leftReg);
    stream << "mv " << destReg << ", " << leftReg << std::endl;
    context.deallocateReg(leftReg);
    std::string rightReg = context.allocateReg(stream);
    right_->EmitRISC(stream, context, rightReg);
    stream << "sgt " << destReg << ", " << destReg << ", " << rightReg
           << std::endl;
    stream << "xori " << destReg << ", " << destReg << ", 1" << std::endl;
    context.deallocateReg(rightReg);
}

void LessThanEqual::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " <= ";
    right_->Print(stream);
}

data_type LessThanEqual::getType(Context &context) const
{
    return data_type::_int;
}

// -------------------------- GreaterThanEqual --------------------------

void GreaterThanEqual::EmitRISC(std::ostream &stream, Context &context) const {}

void GreaterThanEqual::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
    // Change to reg spill
    std::string leftReg = context.allocateReg(stream);
    left_->EmitRISC(stream, context, leftReg);
    stream << "mv " << destReg << ", " << leftReg << std::endl;
    context.deallocateReg(leftReg);
    std::string rightReg = context.allocateReg(stream);
    right_->EmitRISC(stream, context, rightReg);
    stream << "slt " << destReg << ", " << destReg << ", " << rightReg
           << std::endl;
    stream << "xori " << destReg << ", " << destReg << ", 1" << std::endl;
    context.deallocateReg(rightReg);
}

void GreaterThanEqual::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " >= ";
    right_->Print(stream);
}

data_type GreaterThanEqual::getType(Context &context) const
{
    return data_type::_int;
}

