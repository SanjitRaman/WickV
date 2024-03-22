#include "ast/operators/ast_unary.hpp"

void Unary::EmitRISC(std::ostream &stream, Context &context) const {}
void Unary::EmitRISC(std::ostream &stream, Context &context,
                     std::string destReg) const
{
    if (unary_op_ == "&")
    {
        // TODO: Change all context.bindings.at to getOffset
        std::string offset = context.getOffset(cast_expression_->getId());
        stream << "addi " << destReg << ", sp, " << offset << std::endl;
    }
    //TODO: Implement more types
    else if (unary_op_ == "*")
    {
        if (getType(context) == data_type::_float){
            std::cout << "Goes to Unary * " << std::endl;
            std::string offset = context.getOffset(cast_expression_->getId());
            stream << "flw " << destReg << ", " << offset << "(sp)" << std::endl;
            stream << "flw " << destReg << ", 0"
               << "(" << destReg << ")" << std::endl;
        }
        else if (getType(context) == data_type::_double){
            std::cout << "Goes to Unary * " << std::endl;
            std::string offset = context.getOffset(cast_expression_->getId());
            stream << "fld " << destReg << ", " << offset << "(sp)" << std::endl;
            stream << "fld " << destReg << ", 0"
               << "(" << destReg << ")" << std::endl;
        }
        else if (getType(context) == data_type::_int){
            std::cout << "Goes to Unary * " << std::endl;
            std::string offset = context.getOffset(cast_expression_->getId());
            stream << "lw " << destReg << ", " << offset << "(sp)" << std::endl;
            stream << "lw " << destReg << ", 0"
               << "(" << destReg << ")" << std::endl;
        }
        else if (getType(context) == data_type::_char){
            std::string offset = context.getOffset(cast_expression_->getId());
            stream << "lw " << destReg << ", " << offset << "(sp)" << std::endl;
            stream << "lbu " << destReg << ", 0(" << destReg << ")" << std::endl;
        }
    }
    else if (unary_op_ == "-")
    {
        if (getType(context) == data_type::_float || getType(context) == data_type::_double){
            std::string op1_reg = context.allocateFloatReg(stream);
            cast_expression_->EmitRISC(stream, context, op1_reg);
            if (getType(context) == data_type::_float){
                stream << "fsub.s " << destReg << ", " << op1_reg << ", zero" << std::endl;
            }
            else if (getType(context) == data_type::_double){
                stream << "fsub.d " << destReg << ", " << op1_reg << ", zero" << std::endl;
            }
            context.deallocateFloatReg(op1_reg);
        }
        else if (getType(context) == data_type::_int){
            std::string op1_reg = context.allocateReg(stream);
            cast_expression_->EmitRISC(stream, context, op1_reg);
            stream << "sub " << destReg << ", zero, " << op1_reg << std::endl;
            context.deallocateReg(op1_reg);
        }
    }
    else if (unary_op_ == "~"){
        std::string op1_reg = context.allocateReg(stream);
        cast_expression_->EmitRISC(stream, context, op1_reg);
        stream << "not " << destReg << ", " << op1_reg << std::endl;
        context.deallocateReg(op1_reg);
    }
    else if (unary_op_ == "!"){
        std::string op1_reg = context.allocateReg(stream);
        cast_expression_->EmitRISC(stream, context, op1_reg);
        stream << "seqz " << destReg << ", " << op1_reg << std::endl;
        context.deallocateReg(op1_reg);
    }
    else if (unary_op_ == "-"){
        if (getType(context) == data_type::_float || getType(context) == data_type::_double){
            std::string op1_reg = context.allocateFloatReg(stream);
            cast_expression_->EmitRISC(stream, context, op1_reg);
            if (getType(context) == data_type::_float){
                stream << "fsub.s " << destReg << ", " << op1_reg << ", zero" << std::endl;
            }
            else if (getType(context) == data_type::_double){
                stream << "fsub.d " << destReg << ", " << op1_reg << ", zero" << std::endl;
            }
            context.deallocateFloatReg(op1_reg);
        }
        else if (getType(context) == data_type::_int || getType(context) == data_type::_char){
            std::string op1_reg = context.allocateReg(stream);
            cast_expression_->EmitRISC(stream, context, op1_reg);
            stream << "sub " << destReg << ", zero, " << op1_reg << std::endl;
            context.deallocateReg(op1_reg);
        }
    }
}
entity_type Unary::getEntity() const
{
    if (unary_op_ == "*")
    {
        return entity_type::POINTER_DEREFERENCE;
    }
    else if (unary_op_ == "&")
    {
        return entity_type::POINTER_ADDRESS;
    }
    else
    {
        return entity_type::UNARY;
    }
}

std::string Unary::getId() const
{
    // TODO : Implement/check this
    return cast_expression_->getId();
}

void Unary::Print(std::ostream &stream) const
{
    stream << unary_op_;
    cast_expression_->Print(stream);
}
// Try not to use below method
//  void Unary::setType(entity_type type)
//  {
//   declarator_->setType(type);
//  }

data_type Unary::getType(Context &context) const
{
    if (unary_op_ == "*"){
        return cast_expression_->getType(context);
    }
    else{
        return cast_expression_->getType(context);
    }
    
}