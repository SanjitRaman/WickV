#include "ast/operators/ast_operators.hpp"

// ---------------------------- AddOperator ----------------------------

void AddOperator::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const
{
    if (context.getIsPointer(op1_->getId()))
    {
        int mem_index = INT_MEM;
        if (context.getBindingType(op1_->getId()) == data_type::_int)
        {
            mem_index = INT_MEM;
        }
        else if (context.getBindingType(op1_->getId()) == data_type::_float)
        {
            mem_index = FLOAT_MEM;
        }
        else if (context.getBindingType(op1_->getId()) == data_type::_double)
        {
            mem_index = DOUBLE_MEM;
        }
        else if (context.getBindingType(op1_->getId()) == data_type::_char)
        {
            mem_index = CHAR_MEM;
        }
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "addi " << destReg << ", " << destReg << ", " << mem_index
               << std::endl;
        stream << "mul " << op2_reg << ", " << op2_reg << ", " << destReg
               << std::endl;
        stream << "add " << destReg << ", " << op2_reg << ", zero" << std::endl;
        context.deallocateReg(op2_reg);
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << destReg << ", " << op1_reg
               << std::endl;
        context.deallocateReg(op1_reg);
    }
    else if (context.getIsPointer(op2_->getId()))
    {
        int mem_index = INT_MEM;
        if (context.getBindingType(op2_->getId()) == data_type::_int)
        {
            mem_index = INT_MEM;
        }
        else if (context.getBindingType(op2_->getId()) == data_type::_float)
        {
            mem_index = FLOAT_MEM;
        }
        else if (context.getBindingType(op2_->getId()) == data_type::_double)
        {
            mem_index = DOUBLE_MEM;
        }
        else if (context.getBindingType(op2_->getId()) == data_type::_char)
        {
            mem_index = CHAR_MEM;
        }
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "addi " << destReg << ", " << destReg << ", " << mem_index
               << std::endl;
        stream << "mul " << op1_reg << ", " << op1_reg << ", " << destReg
               << std::endl;
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "add " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
    else
    {
        if (getType(context) == data_type::_int)
        {
            std::string op1_reg = context.allocateReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "add " << destReg << ", " << op1_reg << ", zero"
                   << std::endl;
            context.deallocateReg(op1_reg);
            std::string op2_reg = context.allocateReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "add " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateReg(op2_reg);
        }
        else if (getType(context) == data_type::_float)
        {
            std::string op1_reg = context.allocateFloatReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "fmv.s " << destReg << ", " << op1_reg << std::endl;
            context.deallocateFloatReg(op1_reg);
            std::string op2_reg = context.allocateFloatReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "fadd.s " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateFloatReg(op2_reg);
        }
        else if (getType(context) == data_type::_double)
        {
            std::string op1_reg = context.allocateFloatReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "fmv.d " << destReg << ", " << op1_reg << std::endl;
            context.deallocateFloatReg(op1_reg);
            std::string op2_reg = context.allocateFloatReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "fadd.d " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateFloatReg(op2_reg);
        }
        else if (getType(context) == data_type::_char)
        {
            std::string op1_reg = context.allocateReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "add " << destReg << ", " << op1_reg << ", zero"
                   << std::endl;
            context.deallocateReg(op1_reg);
            std::string op2_reg = context.allocateReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "add " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateReg(op2_reg);
        }
    }
}

void AddOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void AddOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " + ";
    op2_->Print(stream);
    stream << ")";
}

data_type AddOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_double ||
        op2_->getType(context) == data_type::_double)
    {
        return data_type::_double;
    }
    else if (op1_->getType(context) == data_type::_float ||
             op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// ---------------------------- SubtractOperator ----------------------------
// TODO: Update this to handle float and double and pointers
void SubtractOperator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
    // Your code here
    if (context.getIsPointer(op1_->getId()))
    {
        int mem_index = INT_MEM;
        if (context.getBindingType(op1_->getId()) == data_type::_int)
        {
            mem_index = INT_MEM;
        }
        else if (context.getBindingType(op1_->getId()) == data_type::_float)
        {
            mem_index = FLOAT_MEM;
        }
        else if (context.getBindingType(op1_->getId()) == data_type::_double)
        {
            mem_index = DOUBLE_MEM;
        }
        else if (context.getBindingType(op1_->getId()) == data_type::_char)
        {
            mem_index = CHAR_MEM;
        }
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "addi " << destReg << ", " << destReg << ", " << mem_index
               << std::endl;
        stream << "mul " << op2_reg << ", " << op2_reg << ", " << destReg
               << std::endl;
        stream << "add " << destReg << ", " << op2_reg << ", zero" << std::endl;
        context.deallocateReg(op2_reg);
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "sub " << destReg << ", " << destReg << ", " << op1_reg
               << std::endl;
        context.deallocateReg(op1_reg);
    }
    else if (context.getIsPointer(op2_->getId()))
    {
        int mem_index = INT_MEM;
        if (context.getBindingType(op2_->getId()) == data_type::_int)
        {
            mem_index = INT_MEM;
        }
        else if (context.getBindingType(op2_->getId()) == data_type::_float)
        {
            mem_index = FLOAT_MEM;
        }
        else if (context.getBindingType(op2_->getId()) == data_type::_double)
        {
            mem_index = DOUBLE_MEM;
        }
        else if (context.getBindingType(op2_->getId()) == data_type::_char)
        {
            mem_index = CHAR_MEM;
        }
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "addi " << destReg << ", " << destReg << ", " << mem_index
               << std::endl;
        stream << "mul " << op1_reg << ", " << op1_reg << ", " << destReg
               << std::endl;
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "sub " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
    else
    {
        if (getType(context) == data_type::_int)
        {
            std::string op1_reg = context.allocateReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "add " << destReg << ", " << op1_reg << ", zero"
                   << std::endl;
            context.deallocateReg(op1_reg);
            std::string op2_reg = context.allocateReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "sub " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateReg(op2_reg);
        }
        else if (getType(context) == data_type::_float)
        {
            std::string op1_reg = context.allocateFloatReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "fmv.s " << destReg << ", " << op1_reg << std::endl;
            context.deallocateFloatReg(op1_reg);
            std::string op2_reg = context.allocateFloatReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "fsub.s " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateFloatReg(op2_reg);
        }
        else if (getType(context) == data_type::_double)
        {
            std::string op1_reg = context.allocateFloatReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "fmv.d " << destReg << ", " << op1_reg << std::endl;
            context.deallocateFloatReg(op1_reg);
            std::string op2_reg = context.allocateFloatReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "fsub.d " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateFloatReg(op2_reg);
        }
        else if (getType(context) == data_type::_char)
        {
            std::string op1_reg = context.allocateReg(stream);  //""
            std::cout << op1_reg << std::endl;
            std::cout << op1_->getId() << std::endl;
            std::cout << op2_->getId() << std::endl;
            op1_->EmitRISC(stream, context, op1_reg);
            stream << "add " << destReg << ", " << op1_reg << ", zero"
                   << std::endl;
            context.deallocateReg(op1_reg);
            std::string op2_reg = context.allocateReg(stream);
            std::cout << op2_reg << std::endl;
            op2_->EmitRISC(stream, context, op2_reg);
            stream << "sub " << destReg << ", " << destReg << ", " << op2_reg
                   << std::endl;
            context.deallocateReg(op2_reg);
        }
    }
}

void SubtractOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void SubtractOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " - ";
    op2_->Print(stream);
    stream << ")";
}

data_type SubtractOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_double ||
        op2_->getType(context) == data_type::_double)
    {
        return data_type::_double;
    }
    else if (op1_->getType(context) == data_type::_float ||
             op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// ---------------------------- MultiplyOperator ----------------------------
void MultiplyOperator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
    if (getType(context) == data_type::_int)
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "mul " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
    else if (getType(context) == data_type::_float)
    {
        std::string op1_reg = context.allocateFloatReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "fmv.s " << destReg << ", " << op1_reg << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string op2_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "fmul.s " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateFloatReg(op2_reg);
    }
    else if (getType(context) == data_type::_double)
    {
        std::string op1_reg = context.allocateFloatReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "fmv.d " << destReg << ", " << op1_reg << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string op2_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "fmul.d " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateFloatReg(op2_reg);
    }
    else if (getType(context) == data_type::_char)
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "mul " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
}

void MultiplyOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void MultiplyOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " * ";
    op2_->Print(stream);
    stream << ")";
}

data_type MultiplyOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_double ||
        op2_->getType(context) == data_type::_double)
    {
        return data_type::_double;
    }
    else if (op1_->getType(context) == data_type::_float ||
             op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// ---------------------------- DivideOperator ----------------------------

void DivideOperator::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
    if (getType(context) == data_type::_int)
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "div " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
    else if (getType(context) == data_type::_float)
    {
        std::string op1_reg = context.allocateFloatReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "fmv.s " << destReg << ", " << op1_reg << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string op2_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "fdiv.s " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateFloatReg(op2_reg);
    }
    else if (getType(context) == data_type::_double)
    {
        std::string op1_reg = context.allocateFloatReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "fmv.d " << destReg << ", " << op1_reg << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string op2_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "fdiv.d " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateFloatReg(op2_reg);
    }
    else if (getType(context) == data_type::_char)
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "div " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
}

void DivideOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void DivideOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " / ";
    op2_->Print(stream);
    stream << ")";
}

data_type DivideOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_double ||
        op2_->getType(context) == data_type::_double)
    {
        return data_type::_double;
    }
    else if (op1_->getType(context) == data_type::_float ||
             op2_->getType(context) == data_type::_float)
    {
        return data_type::_float;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// -------------------------- BitwiseAndOperator --------------------------

void BitwiseAndOperator::EmitRISC(std::ostream &stream, Context &context,
                                  std::string destReg) const
{
    std::string op1_reg = context.allocateReg(stream);
    op1_->EmitRISC(stream, context, op1_reg);
    stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    op2_->EmitRISC(stream, context, op2_reg);
    stream << "and " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    context.deallocateReg(op2_reg);
}

void BitwiseAndOperator::EmitRISC(std::ostream &stream, Context &context) const
{
}

void BitwiseAndOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " & ";
    op2_->Print(stream);
    stream << ")";
}

data_type BitwiseAndOperator::getType(Context &context) const
{
    return data_type::_int;
}

// -------------------------- BitwiseOrOperator --------------------------

void BitwiseOrOperator::EmitRISC(std::ostream &stream, Context &context,
                                 std::string destReg) const
{
    std::string op1_reg = context.allocateReg(stream);
    op1_->EmitRISC(stream, context, op1_reg);
    stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    op2_->EmitRISC(stream, context, op2_reg);
    stream << "or " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    context.deallocateReg(op2_reg);
}

void BitwiseOrOperator::EmitRISC(std::ostream &stream, Context &context) const
{
}

void BitwiseOrOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " | ";
    op2_->Print(stream);
    stream << ")";
}

data_type BitwiseOrOperator::getType(Context &context) const
{
    return data_type::_int;
}

// -------------------------- BitwiseXorOperator --------------------------

void BitwiseXorOperator::EmitRISC(std::ostream &stream, Context &context,
                                  std::string destReg) const
{
    std::string op1_reg = context.allocateReg(stream);
    op1_->EmitRISC(stream, context, op1_reg);
    stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
    context.deallocateReg(op1_reg);
    std::string op2_reg = context.allocateReg(stream);
    op2_->EmitRISC(stream, context, op2_reg);
    stream << "xor " << destReg << ", " << destReg << ", " << op2_reg
           << std::endl;
    context.deallocateReg(op2_reg);
}

void BitwiseXorOperator::EmitRISC(std::ostream &stream, Context &context) const
{
}

void BitwiseXorOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " ^ ";
    op2_->Print(stream);
    stream << ")";
}

data_type BitwiseXorOperator::getType(Context &context) const
{
    return data_type::_int;
}

// -------------------------- ModulusOperator --------------------------

void ModulusOperator::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
    if (getType(context) == data_type::_int)
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "rem " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
    else if (getType(context) == data_type::_unsigned)
    {
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "add " << destReg << ", " << op1_reg << ", zero" << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "remu " << destReg << ", " << destReg << ", " << op2_reg
               << std::endl;
        context.deallocateReg(op2_reg);
    }
}

void ModulusOperator::EmitRISC(std::ostream &stream, Context &context) const {}

void ModulusOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " % ";
    op2_->Print(stream);
    stream << ")";
}

data_type ModulusOperator::getType(Context &context) const
{
    if (op1_->getType(context) == data_type::_unsigned ||
        op2_->getType(context) == data_type::_unsigned)
    {
        return data_type::_unsigned;
    }
    // default
    else
    {
        return data_type::_int;
    }
}

// -------------------------- LogicalAndOperator --------------------------
// TODO: for pointers?
void LogicalAndOperator::EmitRISC(std::ostream &stream, Context &context,
                                  std::string destReg) const
{
    if (op1_->getType(context) == data_type::_int ||
        op1_->getType(context) == data_type::_unsigned ||
        op1_->getType(context) == data_type::_char)
    {
        std::string true_label = context.makeLabel("and_true");
        std::string false_label = context.makeLabel("and_false");
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "beqz " << op1_reg << ", " << false_label << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "beqz " << op2_reg << ", " << false_label << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << "j " << true_label << std::endl;
        context.deallocateReg(op2_reg);
        stream << false_label << ":" << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << true_label << ":" << std::endl;
    }
    else if (op1_->getType(context) == data_type::_float)
    {
        std::string true_label = context.makeLabel("and_true");
        std::string false_label = context.makeLabel("and_false");
        std::string op1_reg = context.allocateFloatReg(stream);
        std::string op2_reg = context.allocateFloatReg(stream);
        std::string and_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "feq.s " << and_reg << ", " << op1_reg << ", " << op2_reg
               << std::endl;
        stream << "beqz " << and_reg << ", " << false_label << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string zero_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "feq.s " << and_reg << ", " << op2_reg << ", " << zero_reg
               << std::endl;
        stream << "beqz " << and_reg << ", " << false_label << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << "j " << true_label << std::endl;
        context.deallocateFloatReg(op2_reg);
        context.deallocateFloatReg(zero_reg);
        context.deallocateReg(and_reg);
        stream << false_label << ":" << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << true_label << ":" << std::endl;
    }
    else if (op1_->getType(context) == data_type::_double)
    {
        std::string true_label = context.makeLabel("and_true");
        std::string false_label = context.makeLabel("and_false");
        std::string op1_reg = context.allocateFloatReg(stream);
        std::string op2_reg = context.allocateFloatReg(stream);
        std::string and_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "feq.d " << and_reg << ", " << op1_reg << ", " << op2_reg
               << std::endl;
        stream << "beqz " << and_reg << ", " << false_label << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string zero_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "feq.d " << and_reg << ", " << op2_reg << ", " << zero_reg
               << std::endl;
        stream << "beqz " << and_reg << ", " << false_label << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << "j " << true_label << std::endl;
        context.deallocateFloatReg(op2_reg);
        context.deallocateFloatReg(zero_reg);
        context.deallocateReg(and_reg);
        stream << false_label << ":" << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << true_label << ":" << std::endl;
    }
    // Default
    else
    {
        std::string true_label = context.makeLabel("and_true");
        std::string false_label = context.makeLabel("and_false");
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "beqz " << op1_reg << ", " << false_label << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "beqz " << op2_reg << ", " << false_label << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << "j " << true_label << std::endl;
        context.deallocateReg(op2_reg);
        stream << false_label << ":" << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << true_label << ":" << std::endl;
    }
}

void LogicalAndOperator::EmitRISC(std::ostream &stream, Context &context) const
{
}

void LogicalAndOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " && ";
    op2_->Print(stream);
    stream << ")";
}

data_type LogicalAndOperator::getType(Context &context) const
{
    return data_type::_int;
}

// -------------------------- LogicalOrOperator --------------------------
// TODO: Check
void LogicalOrOperator::EmitRISC(std::ostream &stream, Context &context,
                                 std::string destReg) const
{
    if (op1_->getType(context) == data_type::_int ||
        op1_->getType(context) == data_type::_unsigned ||
        op1_->getType(context) == data_type::_char)
    {
        std::string true_label = context.makeLabel("or_true");
        std::string false_label = context.makeLabel("or_false");
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "bnez " << op1_reg << ", " << true_label << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "bnez " << op2_reg << ", " << true_label << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << "j " << false_label << std::endl;
        context.deallocateReg(op2_reg);
        stream << true_label << ":" << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << false_label << ":" << std::endl;
    }
    else if (op1_->getType(context) == data_type::_float)
    {
        std::string true_label = context.makeLabel("or_true");
        std::string false_label = context.makeLabel("or_false");
        std::string op1_reg = context.allocateFloatReg(stream);
        std::string op2_reg = context.allocateFloatReg(stream);
        std::string or_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "fne.s " << or_reg << ", " << op1_reg << ", " << op2_reg
               << std::endl;
        stream << "bnez " << or_reg << ", " << true_label << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string zero_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "fne.s " << or_reg << ", " << op2_reg << ", " << zero_reg
               << std::endl;
        stream << "bnez " << or_reg << ", " << true_label << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << "j " << false_label << std::endl;
        context.deallocateFloatReg(op2_reg);
        context.deallocateFloatReg(zero_reg);
        context.deallocateReg(or_reg);
        stream << true_label << ":" << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << false_label << ":" << std::endl;
    }
    else if (op1_->getType(context) == data_type::_double)
    {
        std::string true_label = context.makeLabel("or_true");
        std::string false_label = context.makeLabel("or_false");
        std::string op1_reg = context.allocateFloatReg(stream);
        std::string op2_reg = context.allocateFloatReg(stream);
        std::string or_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "fne.d " << or_reg << ", " << op1_reg << ", " << op2_reg
               << std::endl;
        stream << "bnez " << or_reg << ", " << true_label << std::endl;
        context.deallocateFloatReg(op1_reg);
        std::string zero_reg = context.allocateFloatReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "fne.d " << or_reg << ", " << op2_reg << ", " << zero_reg
               << std::endl;
        stream << "bnez " << or_reg << ", " << true_label << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << "j " << false_label << std::endl;
        context.deallocateFloatReg(op2_reg);
        context.deallocateFloatReg(zero_reg);
        context.deallocateReg(or_reg);
        stream << true_label << ":" << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << false_label << ":" << std::endl;
    }
    // Default
    else
    {
        std::string true_label = context.makeLabel("or_true");
        std::string false_label = context.makeLabel("or_false");
        std::string op1_reg = context.allocateReg(stream);
        op1_->EmitRISC(stream, context, op1_reg);
        stream << "bnez " << op1_reg << ", " << true_label << std::endl;
        context.deallocateReg(op1_reg);
        std::string op2_reg = context.allocateReg(stream);
        op2_->EmitRISC(stream, context, op2_reg);
        stream << "bnez " << op2_reg << ", " << true_label << std::endl;
        stream << "li " << destReg << ", 0" << std::endl;
        stream << "j " << false_label << std::endl;
        context.deallocateReg(op2_reg);
        stream << true_label << ":" << std::endl;
        stream << "li " << destReg << ", 1" << std::endl;
        stream << false_label << ":" << std::endl;
    }
}

void LogicalOrOperator::EmitRISC(std::ostream &stream, Context &context) const
{
}

void LogicalOrOperator::Print(std::ostream &stream) const
{
    stream << "(";
    op1_->Print(stream);
    stream << " || ";
    op2_->Print(stream);
    stream << ")";
}

data_type LogicalOrOperator::getType(Context &context) const
{
    return data_type::_int;
}