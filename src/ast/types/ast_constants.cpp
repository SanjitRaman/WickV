#include "ast/types/ast_constants.hpp"

// ------------------------ IntConstant ------------------------

void IntConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    // TODO : Is this below code still needed
    stream << "li a0, " << value_ << std::endl;
}

void IntConstant::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    stream << "li " << destReg << ", " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const { stream << value_; }

int IntConstant::getValue() const { return value_; }
std::string IntConstant::getId() const { return "ERROR"; }

data_type IntConstant::getType(Context &context) const
{
    return data_type::_int;
}

data_type IntConstant::getType() const
{
    //
    return data_type::_int;
}

// ------------------------ FloatConstant ------------------------

void FloatConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    // TODO : Is this below code still needed
    stream << "li fa0, " << value_ << std::endl;
}

void FloatConstant::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
    //Check this works for all types of floats
    std::string integerReg = context.allocateReg(stream);
    std::string offset = context.getMemory(FLOAT_MEM);
    stream << "li " << integerReg << ", " << getValue() << std::endl;
    stream << "sw " << integerReg << ", " << offset << "(sp)" << std::endl;
    stream << "flw " << destReg << ", " << offset << "(sp)" << std::endl;
    context.deallocateMemory(FLOAT_MEM);
    //stream << "lui " << integerReg << ", %hi(" << getValue() << ")" << std::endl;
    //stream << "flw " << destReg << ", %lo" << "(" << getValue() << ")" << integerReg << std::endl;
    context.deallocateReg(integerReg); //TODO: check all allocated regs are deallocated

}

void FloatConstant::Print(std::ostream &stream) const { stream << value_; }

int FloatConstant::getValue() const { 
    union FloatConversion converter;
    converter.f = value_;
    return converter.i; 
}


std::string FloatConstant::getId() const { return "ERROR"; }

data_type FloatConstant::getType(Context &context) const
{
    return data_type::_float;
}

data_type FloatConstant::getType() const
{
    //
    return data_type::_float;
}