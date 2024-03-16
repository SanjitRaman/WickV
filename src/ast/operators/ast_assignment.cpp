#include "ast/operators/ast_assignment.hpp"

void Assignment::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string tempReg1 = context.allocateReg(stream);
    std::string tempReg2 = context.allocateReg(stream);

    if (unary_expression_->getEntity() == entity_type::ARRAY)
    {
        context.setFetchIndexReg(true);
        unary_expression_->EmitRISC(stream, context, tempReg1);
        context.setFetchIndexReg(false);
    }
    else
    {
        unary_expression_->EmitRISC(stream, context, tempReg1);
    }

    assignment_expression_->EmitRISC(stream, context, tempReg2);
    if (assignment_operator_ == "=")
    {
        stream << "mv " << tempReg1 << ", " << tempReg2 << std::endl;
    }
    else if (assignment_operator_ == "+=")
    {
        stream << "add " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "-=")
    {
        stream << "sub " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "*=")
    {
        stream << "mul " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "/=")
    {
        stream << "div " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "%=")
    {
        stream << "rem " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "<<=")
    {
        stream << "sll " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == ">>=")
    {
        stream << "sra " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "&=")
    {
        stream << "and " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "^=")
    {
        stream << "xor " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    else if (assignment_operator_ == "|=")
    {
        stream << "or " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
               << std::endl;
    }
    // For integer types
    if (unary_expression_->getEntity() == entity_type::ARRAY)
    {
        // TODO: to optimise, you could keep the address in a register from the
        // beginning of function
        std::string index_reg = context.getIndexReg();
        stream << "sw " << tempReg1 << ", 0(" << index_reg << ")" << std::endl;
        context.deallocateReg(index_reg);
        context.setIndexReg("");
    }
    else if (unary_expression_->getEntity() == entity_type::POINTER)
    {
        std::string offset = context.getOffset(unary_expression_->getId());
        stream << "lw " << tempReg2 << ", " << offset << "(sp)" << std::endl;
        stream << "sw " << tempReg1 << ", 0(" << tempReg2 << ")" << std::endl;
    }
    else
    {
        std::cout << "sw " << tempReg1 << ", "
                  << context.getOffset(unary_expression_->getId()) << "(sp)"
                  << std::endl;
        stream << "sw " << tempReg1 << ", "
               << context.getOffset(unary_expression_->getId()) << "(sp)"
               << std::endl;
    }

    context.deallocateReg(tempReg1);
    context.deallocateReg(tempReg2);
}

void Assignment::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    // Shouldn't need to use this method
}

void Assignment::Print(std::ostream &stream) const
{
    unary_expression_->Print(stream);
    stream << " " << assignment_operator_ << " ";
    assignment_expression_->Print(stream);
    stream << ";" << std::endl;
}
