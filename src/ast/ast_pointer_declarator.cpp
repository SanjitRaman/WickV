#include "ast/ast_pointer_declarator.hpp"

void PointerDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    //TODO: Check if it is a function
    identifier_->EmitRISC(stream, context);
    
}

void PointerDeclarator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
}

entity_type PointerDeclarator::getEntity() const { return entity_type::POINTER; }

std::string PointerDeclarator::getId() const { return identifier_->getId(); }

void PointerDeclarator::Print(std::ostream &stream) const
{
    pointer_->Print(stream);
    identifier_->Print(stream);
}
