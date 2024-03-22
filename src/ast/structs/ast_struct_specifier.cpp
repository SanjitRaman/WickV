#include "ast/structs/ast_struct_specifier.hpp"

void StructSpecifier::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "StructSpecifier::EmitRISC entered. " << std::endl;
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
    std::cout << "Goes to StructSpecifier:EmitRISC(destReg)" << std::endl;
}
entity_type StructSpecifier::getEntity() const
{
    return entity_type::STRUCT_SPECIFIER;
}

std::string StructSpecifier::getId() const { return identifier_; }

void StructSpecifier::Print(std::ostream &stream) const {}