#include "ast/ast_array_declarator.hpp"

void ArrayDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    context.addArray(identifier_->getId(), size_->getValue());
}

void ArrayDeclarator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
}

entity_type ArrayDeclarator::getEntity() const { return entity_type::ARRAY; }

std::string ArrayDeclarator::getId() const { return identifier_->getId(); }

void ArrayDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    stream << "[";
    size_->Print(stream);
    stream << "]";
}
