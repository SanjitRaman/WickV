#include "ast/types/ast_enum_specifier.hpp"

void EnumSpecifier::EmitRISC(std::ostream &stream, Context &context) const {
    context.createEnum(identifier_);
    enumerator_list_->EmitRISC(stream, context);
    context.resetEnumVal();

}



void EnumSpecifier::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
}
void EnumSpecifier::Print(std::ostream &stream) const { 
    stream << "enum " << identifier_ << " {" << std::endl;
    if (enumerator_list_ != nullptr){
        enumerator_list_->Print(stream);
    }
    stream << "}";
 }

entity_type EnumSpecifier::getType() const
{
    return entity_type::ENUM_SPECIFIER;
}

std::string EnumSpecifier::getId() const
{
    return identifier_; 
}
