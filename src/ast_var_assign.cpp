#include "ast_var_assign.hpp"

void VarAssign::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string varReg = context.allocateReg();
    //Assume the binding exists
    if (context.bindings.find(declarator_->getId()) != context.bindings.end()){
        //If it is then execute this code
        std::string offset = context.bindings.at(declarator_->getId()).offset;
        initializer_->EmitRISC(stream, context, varReg); //As it is an assignment, it cannot be null
        stream << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
    }
    stream << "mv " << varReg << ", " << "zero" << std::endl; //Set the register to zero
    context.deallocateReg(varReg);
}
void VarAssign::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{
  //May not be necessary
  //But if it is then assign the value then move to destReg (maybe call var->emitRISC)
}
data_type VarAssign::getType() const 
{
  return declarator_->getType();
}

std::string VarAssign::getId() const
{
  return declarator_->getId(); //Shouldn't go here
}

void VarAssign::Print(std::ostream &stream) const
{

}
//Try not to use below method
// void VarAssign::setType(data_type type)
// {
//  declarator_->setType(type);
// }