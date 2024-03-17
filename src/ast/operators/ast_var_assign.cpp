#include "ast/operators/ast_var_assign.hpp"

void VarAssign::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string varReg;
    // Assume the binding exists
    if (context.bindings.find(declarator_->getId()) != context.bindings.end())
    {
        // If it is then execute this code
        if (getType(context) == data_type::_int){
            varReg = context.allocateReg(stream);
            std::string offset = context.getOffset(declarator_->getId());
            initializer_->EmitRISC(
            stream, context,
            varReg);  // As it is an assignment, it cannot be null
            std::cout << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
            stream << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
            context.deallocateReg(varReg);
        }
        else if (getType(context) == data_type::_float || getType(context) == data_type::_double){
            varReg = context.allocateFloatReg(stream);
            std::string offset = context.getOffset(declarator_->getId());
            initializer_->EmitRISC(
            stream, context,
            varReg);  // As it is an assignment, it cannot be null
            std::cout << "fsw " << varReg << ", " << offset << "(sp)" << std::endl;
            stream << "fsw " << varReg << ", " << offset << "(sp)" << std::endl;
            context.deallocateFloatReg(varReg);
        }
        
    }
    else if (context.params.find(declarator_->getId()) != context.params.end())
    {
        if (getType(context) == data_type::_int){
            varReg = context.allocateReg(stream);
            std::string offset = context.getOffset(declarator_->getId());
            initializer_->EmitRISC(
            stream, context,
            varReg);  // As it is an assignment, it cannot be null
            std::cout << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
            stream << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
            context.deallocateReg(varReg);
        }
        else if (getType(context) == data_type::_float || getType(context) == data_type::_double){
            varReg = context.allocateFloatReg(stream);
            std::string offset = context.getOffset(declarator_->getId());
            initializer_->EmitRISC(
            stream, context,
            varReg);  // As it is an assignment, it cannot be null
            std::cout << "fsw " << varReg << ", " << offset << "(sp)" << std::endl;
            stream << "fsw " << varReg << ", " << offset << "(sp)" << std::endl;
            context.deallocateFloatReg(varReg);
        }
    }
    
}
void VarAssign::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
    // May not be necessary
    // But if it is then assign the value then move to destReg (maybe call
    // var->emitRISC)
}
entity_type VarAssign::getEntity() const
{
    return entity_type::VARIABLE_ASSIGN;
}

data_type VarAssign::getType(Context &context) const
{
    return context.getBindingType(getId()); //Can change to declarator_->getType(context)?
}

std::string VarAssign::getId() const
{
    return declarator_->getId();  // Shouldn't go here
}

void VarAssign::Print(std::ostream &stream) const {}
// Try not to use below method
//  void VarAssign::setType(entity_type type)
//  {
//   declarator_->setType(type);
//  }