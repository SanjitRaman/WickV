#include "ast/types/ast_constants.hpp"

// ------------------------ IntConstant ------------------------

void IntConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    //TODO : Is this below code still needed 
    stream << "li a0, " << value_ << std::endl;
}

void IntConstant::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    stream << "li " << destReg << ", " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const { stream << value_; }

int IntConstant::getValue() const 
{ 
    return value_; 
}
std::string IntConstant::getId() const
{
    return "ERROR";
}

// ------------------------ FloatConstant ------------------------


void FloatConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    //TODO : Is this below code still needed 
    stream << "li a0, " << value_ << std::endl;
}

void FloatConstant::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    
}

void FloatConstant::Print(std::ostream &stream) const { stream << value_; }

int FloatConstant::getValue() const 
{ 
    return value_; 
}
std::string FloatConstant::getId() const
{
    return "ERROR";
}


