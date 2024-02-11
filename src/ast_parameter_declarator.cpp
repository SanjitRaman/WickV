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