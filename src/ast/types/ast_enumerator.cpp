#include "ast/types/ast_enumerator.hpp"

void Enumerator::EmitRISC(std::ostream &stream, Context &context) const
{
    if (constant_expression_ != nullptr)
    {
        context.addEnumVal(identifier_, constant_expression_->getValue());
    }
    else
    {
        context.addEnumVal(identifier_, context.setEnumVal());
    }
}

void Enumerator::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
}
void Enumerator::Print(std::ostream &stream) const
{
    std::cout << identifier_ << " : enumerator::print" << std::endl;
    stream << identifier_;
    // std::cout << constant_expression_ << " : enumerator::print" << std::endl;
    if (constant_expression_ != nullptr)
    {
        // std::cout << "Goes here for some reason : enumerator::print if
        // statement" << std::endl;
        stream << " = ";
        constant_expression_->Print(stream);
    }
}

entity_type Enumerator::getEntity() const
{
    // TODO: is this needed?
    return entity_type::ENUMERATOR;
}

data_type Enumerator::getType() const { return data_type::_int; }

std::string Enumerator::getId() const
{
    // TODO: is this needed?
    return identifier_;
}
