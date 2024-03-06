#include "ast_inequality.hpp"

// -------------------------- GreaterThan --------------------------

void GreaterThan::EmitRISC(std::ostream &stream, Context &context) const
{
    
}

void GreaterThan::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
    //Change to reg spill
    std::string leftReg = context.allocateReg(stream);
    std::string rightReg = context.allocateReg(stream);
    left_->EmitRISC(stream, context, leftReg);
    right_->EmitRISC(stream, context, rightReg);
    stream << "sgt " << destReg << ", " << leftReg << ", " << rightReg << std::endl;
    context.deallocateReg(leftReg);
    context.deallocateReg(rightReg);
}

void GreaterThan::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " > ";
    right_->Print(stream);
}

// -------------------------- LessThan --------------------------

void LessThan::EmitRISC(std::ostream &stream, Context &context) const
{
    
}

void LessThan::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
    //Change to reg spill
    std::string leftReg = context.allocateReg(stream);
    std::string rightReg = context.allocateReg(stream);
    left_->EmitRISC(stream, context, leftReg);
    right_->EmitRISC(stream, context, rightReg);
    stream << "slt " << destReg << ", " << leftReg << ", " << rightReg << std::endl;
    context.deallocateReg(leftReg);
    context.deallocateReg(rightReg);
}

void LessThan::Print(std::ostream &stream) const
{
    left_->Print(stream);
    stream << " < ";
    right_->Print(stream);
}