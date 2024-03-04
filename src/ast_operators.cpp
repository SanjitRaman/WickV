#include "ast_operators.hpp"

void AddOperator::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{
    std::string op1_reg = context.allocateReg(); //""
    std::string op2_reg = context.allocateReg();
    std::cout << op1_reg << std::endl;
    std::cout << op2_reg << std::endl;
    std::cout << op1_->getId() << std::endl;
    std::cout << op2_->getId() << std::endl;
    op1_->EmitRISC(stream, context, op1_reg);
    stream << "add " << destReg << ", " << destReg << ", " << op1_reg << std::endl;
    stream << "mv " << op1_reg << ", zero" << std::endl;
    context.deallocateReg(op1_reg);
    op2_->EmitRISC(stream, context, op2_reg);
    stream << "add " << destReg << ", " << destReg << ", " << op2_reg << std::endl;
    stream << "mv " << op2_reg << ", zero" << std::endl; //Check this
    context.deallocateReg(op2_reg);
}

void AddOperator::EmitRISC(std::ostream &stream, Context &context) const
{
    
}

void AddOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " + ";
    op2_->Print(stream);
    stream << ")";
}
