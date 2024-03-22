#include "ast/operators/ast_prefix.hpp"

void PrefixOperator::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
    // todo support other types such as float, double, char, unsigned
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

void PrefixOperator::EmitRISC(std::ostream &stream, Context &context) const
{
    // TODO: fix this from the postfix operator (current)
    std::string tempReg = context.allocateReg(stream);
    primary_expression_->EmitRISC(stream, context, tempReg);
    if (op_ == "++")
    {
        // Implement increement
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

void PrefixOperator::Print(std::ostream &stream) const
{
    stream << "(";
    primary_expression_->Print(stream);
    stream << op_;
    stream << ")";
}

data_type PrefixOperator::getType(Context &context) const
{
    // TODO: change for different types.
    return data_type::_int;
}
