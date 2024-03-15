#include "ast/types/ast_variable.hpp"
void Variable::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << Id_;
}

void Variable::EmitRISC(std::ostream &stream, Context &context,
                        std::string destReg) const
{
    // This function should move into dest reg and load from memory

    // Check parameter bindings
    int enum_val = context.getEnumVal(getId());
    if (context.params.find(getId()) != context.params.end())
    {
        stream << "lw " << destReg << ", " << context.getOffset(getId())
               << "(sp)" << std::endl;
    }
    // Check local var bindings
    else if (context.bindings.find(getId()) != context.bindings.end())
    {
        stream << "lw " << destReg << ", " << context.getOffset(getId())
               << "(sp)" << std::endl;
    }
    // If the variable is not present in bindings then it must be
    //   a local var which is yet to be initialised in the current scope
    // TODO : TRY TO NOT USE THE BELOW CODE
    else if (enum_val != -1){
        stream << "li " << destReg << ", " << enum_val << std::endl;
    }
    else
    {
        context.createBinding(getId(), getType());
        stream << "sw " << destReg << " " << context.getOffset(getId())
               << "(sp)" << std::endl;
    }

    // Check local var bindings (TODO)

    return;
}
// Try not to use below method
entity_type Variable::getType() const
{
    // return type_;
    return entity_type::VARIABLE;
}

std::string Variable::getId() const { return Id_; }
void Variable::setType(entity_type type) { type_ = type; }

void Variable::Print(std::ostream &stream) const { stream << Id_; };
