#include "ast/operators/ast_assignment.hpp"

void Assignment::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string tempReg1;
    std::string tempReg2;
    data_type result_type = getType(context);

    if (result_type == data_type::_float)
    {
        tempReg1 = context.allocateFloatReg(stream);
    }
    else if (result_type == data_type::_double)
    {
        tempReg1 = context.allocateFloatReg(stream);
    }
    else if (result_type == data_type::_int)
    {
        tempReg1 = context.allocateReg(stream);
    }
    else if (result_type == data_type::_char)
    {
        tempReg1 = context.allocateReg(stream);
    }


    if (assignment_expression_->getType(context) == data_type::_float)
    {
        tempReg2 = context.allocateFloatReg(stream);
    }
    else if (assignment_expression_->getType(context) == data_type::_double)
    {
        tempReg2 = context.allocateFloatReg(stream);
    }
    else if (assignment_expression_->getType(context) == data_type::_int)
    {
        tempReg2 = context.allocateReg(stream);
    }
    else if (assignment_expression_->getType(context) == data_type::_char)
    {
        tempReg2 = context.allocateReg(stream);
    }

    

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
        if (result_type == data_type::_float)
        {
            stream << "fmv.s " << tempReg1 << ", " << tempReg2 << std::endl;
        }
        else if (result_type == data_type::_double)
        {
            stream << "fmv.d " << tempReg1 << ", " << tempReg2 << std::endl;
        }
        else{
            stream << "mv " << tempReg1 << ", " << tempReg2 << std::endl;
        }
    }
    else if (assignment_operator_ == "+=")
    {
        if (result_type == data_type::_float)
        {
            stream << "fadd.s " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else if (result_type == data_type::_double)
        {
            stream << "fadd.d " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else
        {
            stream << "add " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
    }
    else if (assignment_operator_ == "-=")
    {
        if (result_type == data_type::_float)
        {
            stream << "fsub.s " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else if (result_type == data_type::_double)
        {
            stream << "fsub.d " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else
        {
            stream << "sub " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
    }
    else if (assignment_operator_ == "*=")
    {
        if (result_type == data_type::_float)
        {
            stream << "fmul.s " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else if (result_type == data_type::_double)
        {
            stream << "fmul.d " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else
        {
            stream << "mul " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
    }
    else if (assignment_operator_ == "/=")
    {
        if (result_type == data_type::_float)
        {
            stream << "fdiv.s " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else if (result_type == data_type::_double)
        {
            stream << "fdiv.d " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
        else
        {
            stream << "div " << tempReg1 << ", " << tempReg1 << ", " << tempReg2
                   << std::endl;
        }
    }
    //TODO : Implement below operators
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
        if (result_type == data_type::_float || result_type == data_type::_double)
        {
            std::string offset = context.getOffset(unary_expression_->getId());
            stream << "fsw " << tempReg1 << ", " << offset << "(sp)" << std::endl;
        }
        else if (result_type == data_type::_char)
        {
            std::string offset = context.getOffset(unary_expression_->getId());
            stream << "sb " << tempReg1 << ", " << offset << "(sp)" << std::endl;
        }
        else
        {
            std::string offset = context.getOffset(unary_expression_->getId());
            stream << "sw " << tempReg1 << ", " << offset << "(sp)" << std::endl;
        }
    }

    if (result_type == data_type::_float)
    {
        context.deallocateFloatReg(tempReg1);
    }
    else if (result_type == data_type::_double)
    {
        context.deallocateFloatReg(tempReg1);
    }
    else if (result_type == data_type::_int)
    {
        context.deallocateReg(tempReg1);
    }



    if (assignment_expression_->getType(context) == data_type::_float)
    {
        context.deallocateFloatReg(tempReg2);
    }
    else if (assignment_expression_->getType(context) == data_type::_double)
    {
        context.deallocateFloatReg(tempReg2);
    }
    else if (assignment_expression_->getType(context) == data_type::_int)
    {
        context.deallocateReg(tempReg2);
    }
}

void Assignment::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    // Shouldn't need to use this method
}

data_type Assignment::getType(Context &context) const
{
    return unary_expression_->getType(context);
}


void Assignment::Print(std::ostream &stream) const
{
    unary_expression_->Print(stream);
    stream << " " << assignment_operator_ << " ";
    assignment_expression_->Print(stream);
    stream << ";" << std::endl;
}
