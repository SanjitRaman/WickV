#include "ast/operators/ast_unary.hpp"

void Unary::EmitRISC(std::ostream &stream, Context &context) const
{
    
}
void Unary::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
    if (unary_op_ == "&"){
        //TODO: Change all context.bindings.at to getOffset
        std::string offset = context.getOffset(cast_expression_->getId());
        stream << "addi " << destReg << ", sp, " << offset << std::endl;
    }
    else if (unary_op_ == "*"){
        std::string offset = context.getOffset(cast_expression_->getId());
        stream << "li " << destReg << ", " << offset << std::endl;
        stream << "lw " << destReg << ", 0" << "(" << destReg << ")" << std::endl;
        
    }

   
}
entity_type Unary::getType() const { return entity_type::UNARY; }

std::string Unary::getId() const
{
    //TODO : Implement/check this
    return cast_expression_->getId();
}

void Unary::Print(std::ostream &stream) const {}
// Try not to use below method
//  void Unary::setType(entity_type type)
//  {
//   declarator_->setType(type);
//  }