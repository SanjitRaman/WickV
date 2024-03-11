#include "ast/ast_direct_declarator.hpp"

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    identifier_->EmitRISC(stream, context);
    stream << ":" << std::endl;

    // Prolog
    context.CreateScope(stream);
    if (parameter_list_ != nullptr)
    {
        parameter_list_->EmitRISC(stream, context);
    }
}

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
}

entity_type DirectDeclarator::getType() const { return entity_type::FUNCTION; }

std::string DirectDeclarator::getId() const { return identifier_->getId(); }

void DirectDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    if (parameter_list_ != nullptr)
    {
        stream << "(";
        parameter_list_->Print(stream);
        stream << ")";
    }
    else
    {
        stream << "()";
    }
}
