#include "ast_parameter_declarator.hpp"

void ParameterDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
  if (declaration_specifier_ != nullptr)
  {
    declaration_specifier_->EmitRISC(stream, context);
  }
  if (declarator_ != nullptr)
  {
    declarator_->EmitRISC(stream, context);
  }
}

data_type ParameterDeclarator::getType() const 
{
  return declaration_specifier_->getType();
}

std::string ParameterDeclarator::getId() const
{
  return declarator_->getId();
}

void ParameterDeclarator::Print(std::ostream &stream) const
{
  if (declaration_specifier_ != nullptr)
  {
    declaration_specifier_->Print(stream);
    stream << " ";
  }
  if (declarator_ != nullptr)
  {
    declarator_->Print(stream);
  }
}