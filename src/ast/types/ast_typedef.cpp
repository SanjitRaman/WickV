#include "ast/types/ast_typedef.hpp"

void Typedef::EmitRISC(std::ostream &stream,
                          Context &context) const {}

void Typedef::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const {}

void Typedef::Print(std::ostream &stream) const { stream << identifier_; }

// This shouldn't be used ever.
entity_type Typedef::getEntity() const
{
    return entity_type::TYPEDEF_IDENTIFIER;
}

std::string Typedef::getId() const
{
    return identifier_;
}


void TypedefDeclaration::EmitRISC(std::ostream &stream,
                          Context &context) const {}

void TypedefDeclaration::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const {}

void TypedefDeclaration::Print(std::ostream &stream) const { 
    identifier_->Print(stream);
    declaration_specifier_->Print(stream);
    
    
}

// This shouldn't be used ever.
entity_type TypedefDeclaration::getEntity() const
{
    return entity_type::TYPEDEF_DEC;
}

std::string TypedefDeclaration::getId() const
{
    return declaration_specifier_->getId();
}

