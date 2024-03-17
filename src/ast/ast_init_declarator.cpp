#include "ast/ast_init_declarator.hpp"

void InitDeclarator::EmitRISC(std::ostream &stream, Context &context) const {
    if (declarator_ != nullptr)
    {
        if (declarator_->getEntity() == entity_type::ARRAY){
            declarator_->EmitRISC(stream, context);
        }
    }
}
void InitDeclarator::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
}
entity_type InitDeclarator::getEntity() const { return declarator_->getEntity(); }

std::string InitDeclarator::getId() const { return declarator_->getId(); }

void InitDeclarator::Print(std::ostream &stream) const
{
    if (declarator_ != nullptr)
    {
        declarator_->Print(stream);
    }
}