#include "ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << "li a0, " << value_ << std::endl;
}

void IntConstant::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}

void IntConstant::Print(std::ostream &stream) const
{
    stream << value_;
}
