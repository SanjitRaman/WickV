#include "ast/types/ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << "li a0, " << value_ << std::endl;
}

void IntConstant::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    stream << "li " << destReg << ", " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const { stream << value_; }
