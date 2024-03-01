#include "ast_var_declaration.hpp"

void VarDeclaration::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string varReg = context.allocateReg();
    if (context.bindings.find(declarator_->getId()) != context.bindings.end()){
        //If it is then execute this code
        std::string offset = context.bindings.at(declarator_->getId()).offset;
        initializer_->EmitRISC(stream, context, varReg); //As it is an assignment, it cannot be null
        stream << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
    }
    else{
        if (initializer_ != nullptr)
        {
            initializer_->EmitRISC(stream, context, varReg);
        }
        declarator_->EmitRISC(stream, context, varReg);
    }
    stream << "mv " << varReg << ", " << "zero" << std::endl; //Set the register to zero
    context.deallocateReg(varReg);
}
void VarDeclaration::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}
data_type VarDeclaration::getType() const 
{
  return declarator_->getType();
}

std::string VarDeclaration::getId() const
{
  return declarator_->getId(); //Shouldn't go here
}

void VarDeclaration::Print(std::ostream &stream) const
{

}

void VarDeclaration::setType(data_type type)
{
  declarator_->setType(type);
}