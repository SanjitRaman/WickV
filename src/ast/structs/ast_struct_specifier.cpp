#include "ast/ast_struct_specifier.hpp"

void StructSpecifier::EmitRISC(std::ostream &stream, Context &context) const {
    std::unordered_map<std::string, data_type> struct_members;
    for (auto &declaration : struct_declaration_list_->getNodes())
    {
        struct_members[declaration->getId()] = declaration->getType();
    }
    context.InitialiseStruct(identifier_, struct_members);
}
void StructSpecifier::EmitRISC(std::ostream &stream, Context &context,
                              std::string destReg) const
{
}
entity_type StructSpecifier::getEntity() const {  }

std::string StructSpecifier::getId() const {  }

void StructSpecifier::Print(std::ostream &stream) const
{
}