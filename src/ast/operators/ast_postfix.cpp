#include "ast/operators/ast_postfix.hpp"

void PostfixOperator::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
    std::string tempReg = context.allocateReg(stream);
    primary_expression_->EmitRISC(stream, context, tempReg);
    if (op_ == "++")
    {
        stream << "addi " << tempReg << ", " << tempReg << ", 1" << std::endl;
    }
    else if (op_ == "--")
    {
        // Implement decrement
        stream << "addi " << tempReg << ", " << tempReg << ", -1" << std::endl;
    }
    stream << "sw " << tempReg << ", "
           << context.getOffset(primary_expression_->getId()) << "(sp)"
           << std::endl;

    stream << "mv " << destReg << ", " << tempReg << std::endl;
    context.deallocateReg(tempReg);
}

void PostfixOperator::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string tempReg = context.allocateReg(stream);
    primary_expression_->EmitRISC(stream, context, tempReg);
    if (op_ == "++")
    {
        stream << "addi " << tempReg << ", " << tempReg << ", 1" << std::endl;
    }
    else if (op_ == "--")
    {
        // Implement decrement
        stream << "addi " << tempReg << ", " << tempReg << ", -1" << std::endl;
    }
    stream << "sw " << tempReg << ", "
           << context.getOffset(primary_expression_->getId()) << "(sp)"
           << std::endl;
    context.deallocateReg(tempReg);
}

void PostfixOperator::Print(std::ostream &stream) const
{
    stream << "(";
    primary_expression_->Print(stream);
    stream << op_;
    stream << ")";
}

data_type PostfixOperator::getType(Context &context) const
{
    return data_type::_int;
}
