#include "ast/structs/ast_member_access.hpp"

void MemberAccess::EmitRISC(std::ostream &stream, Context &context) const {}
void MemberAccess::EmitRISC(std::ostream &stream, Context &context,
                            std::string destReg) const
{
    std::string offset = context.getOffset(getId());
    if (getType(context) == data_type::_float ||
        getType(context) == data_type::_double)
    {
        stream << "flw  " << destReg << ", " << offset << "(sp)" << std::endl;
    }
    else
    {
        stream << "lw " << destReg << ", " << offset << "(sp)" << std::endl;
    }
}
entity_type MemberAccess::getEntity() const
{
    return entity_type::VARIABLE;  // TODO
}

std::string MemberAccess::getId() const
{
    // TODO: Implement a class for struct_declarator_list
    // which inherits from NodeList and has a custom getId
    return struct_name_->getId() + "." + member_name_;
    ;
}

void MemberAccess::Print(std::ostream &stream) const {}

data_type MemberAccess::getType(Context &context) const
{
    return context.getBindingType(getId());
}  // Shouldn't need one with context