#include "ast/ast_pointer_declarator.hpp"

void PointerDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    
}

void PointerDeclarator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
}

entity_type PointerDeclarator::getType() const { return entity_type::POINTER; }

std::string PointerDeclarator::getId() const { return identifier_->getId(); }

void PointerDeclarator::Print(std::ostream &stream) const
{
    pointer_->Print(stream);
    identifier_->Print(stream);
}
