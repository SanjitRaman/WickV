#include "ast/operators/ast_operators.hpp"

// ---------------------------- AddOperator ----------------------------

void AddOperator::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    if (context.getIsPointer(op1_->getId()))
    {
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "addi " << destReg << ", " << destReg << ", " << INT_MEM
               << std::endl;
        stream << "mul " << op2_reg << ", " << op2_reg << ", " << destReg
               << std::endl;
        stream << "add " << destReg << ", " << op2_reg << ", zero" << std::endl;
        context.deallocateReg(op2_reg);
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << destReg << ", " << op1_reg
               << std::endl;
        context.deallocateReg(op1_reg);
    }
    else if (context.getIsPointer(op2_->getId()))
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "addi " << destReg << ", " << destReg << ", " << INT_MEM
               << std::endl;
        stream << "mul " << op1_reg << ", " << op1_reg << ", " << destReg
               << std::endl;
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "add " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
    else
    {
        if (getType(context) == data_type::_int)
        {
            std::string op1_reg = context.allocateReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "add " << destReg << ", " << op1_reg << ", zero"
                   << std::endl;
            context.deallocateReg(op1_reg);
            std::string op2_reg = context.allocateReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "add " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateReg(op2_reg);
        }
        else if (getType(context) == data_type::_float)
        {
            std::string op1_reg = context.allocateFloatReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "fmv.s " << destReg << ", " << op1_reg << std::endl;
            context.deallocateFloatReg(op1_reg);
            std::string op2_reg = context.allocateFloatReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "fadd.s " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateFloatReg(op2_reg);
        }
    }
}

void AddOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void AddOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " + ";
    op2_->Print(stream);
    stream << ")";
}

data_type AddOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_float ||
        op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// ---------------------------- SubtractOperator ----------------------------
void SubtractOperator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
    // Change to reg spill
    std::string op1_reg = context.allocateReg(stream);
    op1_->EmitRISC(stream, context, op1_reg);
    stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    op2_->EmitRISC(stream, context, op2_reg);
    stream << "sub " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    context.deallocateReg(op2_reg);
}

void SubtractOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void SubtractOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " - ";
    op2_->Print(stream);
    stream << ")";
}

data_type SubtractOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_float ||
        op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// ---------------------------- MultiplyOperator ----------------------------
void MultiplyOperator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
    std::string op1_reg = context.allocateReg(stream);
    op1_->EmitRISC(stream, context, op1_reg);
    stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    op2_->EmitRISC(stream, context, op2_reg);
    stream << "mul " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    context.deallocateReg(op2_reg);
}

void MultiplyOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void MultiplyOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " * ";
    op2_->Print(stream);
    stream << ")";
}

data_type MultiplyOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_float ||
        op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}