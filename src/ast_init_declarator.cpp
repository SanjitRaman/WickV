#include "ast_init_declarator.hpp"

void InitDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
  
}
void InitDeclarator::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}
data_type InitDeclarator::getType() const 
{
    //Shouldn't need to be called
}

std::string InitDeclarator::getId() const
{
  return declarator_->getId();
}

void InitDeclarator::Print(std::ostream &stream) const
{
  if (declarator_ != nullptr)
  {
    declarator_->Print(stream);
  }
}