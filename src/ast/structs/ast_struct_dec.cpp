#include "ast/structs/ast_struct_dec.hpp"

void StructDec::EmitRISC(std::ostream &stream, Context &context) const {}
void StructDec::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
}
entity_type StructDec::getEntity() const { return entity_type::STRUCT_DEC; }

std::string StructDec::getId() const { return identifier_; }

void StructDec::Print(std::ostream &stream) const {}

data_type StructDec::getType(Context &context) const
{
    return data_type::_INVALID;
}  // Shouldn't need one with context