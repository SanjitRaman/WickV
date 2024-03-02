#include "ast_assignment.hpp"

void Assignment::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string tempReg1 = context.allocateReg();
    std::string tempReg2 = context.allocateReg();
    unary_expression_->EmitRISC(stream, context, tempReg1);
    assignment_expression_->EmitRISC(stream, context, tempReg2);
    if (assignment_operator_ == "=")
    {
        stream << "mv " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "+=")
    {
        stream << "add " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "-=")
    {
        stream << "sub " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "*=")
    {
        stream << "mul " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "/=")
    {
        stream << "div " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "%=")
    {
        stream << "rem " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "<<=")
    {
        stream << "sll " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == ">>=")
    {
        stream << "sra " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "&=")
    {
        stream << "and " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "^=")
    {
        stream << "xor " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "|=")
    {
        stream << "or " << tempReg1 << ", " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    //For integer types
    
    stream << "sw " << tempReg1 << ", " << context.bindings.at(unary_expression_->getId()).offset << "(sp)" << std::endl; 
    
    stream << "mv " << tempReg1 << ", " << "zero" << std::endl;
    stream << "mv " << tempReg2 << ", " << "zero" << std::endl;
    context.deallocateReg(tempReg1);
    context.deallocateReg(tempReg2);
}

void Assignment::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{
    //Shouldn't need to use this method
}

void Assignment::Print(std::ostream &stream) const
{
    unary_expression_->Print(stream);
    stream << " " << assignment_operator_ << " ";
    assignment_expression_->Print(stream);
    stream << ";" << std::endl;
}
