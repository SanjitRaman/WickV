#include "ast/types/ast_variable.hpp"
void Variable::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << Id_;
}

void Variable::EmitRISC(std::ostream &stream, Context &context,
                        std::string destReg) const
{
    // This function should move into dest reg and load from memory
    // TODO: Below is a way we can add support for floats (simply add
    // floating_expr before "lw") std::string floating_repr = "";
    //        if (datatype == "float" || datatype == "double" || datatype ==
    //        "long double"){
    //            floating_repr = "f";
    //        }

    // Check parameter bindings
    int enum_val = context.getEnumVal(getId());
    if (context.params.find(getId()) != context.params.end())
    {
        data_type var_type = context.getBindingType(getId());
        //std::cout << "Variable type: " << var_type << std::endl;
        if (var_type == data_type::_int)
        {
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_float)
        {
            // TODO: check that the destReg is a float register.
            stream << "flw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_double)
        {
            stream << "fld " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_char && context.getIsPointer(getId())){
            std::cout << "Goes to Char * " << std::endl;
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_char)
        {
            stream << "lbu " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else
        {
            // defaults to the int implementation.
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
    }
    // Check local var bindings
    else if (context.bindings.find(getId()) != context.bindings.end())
    {
        data_type var_type = context.getBindingType(getId());
        if (var_type == data_type::_int)
        {
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_float)
        {
            // TODO: check that the destReg is a float register.
            stream << "flw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_double)
        {
            stream << "fld " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_char && context.getIsPointer(getId())){
            std::cout << "Goes to Char * " << std::endl;
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else if (var_type == data_type::_char)
        {
            stream << "lbu " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
        else
        {
            // defaults to the int implementation.
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
        }
    }
    else if (enum_val != -1)
    {
        stream << "li " << destReg << ", " << enum_val << std::endl;
    }
    // If the variable is not present in bindings then it must be
    //   a local var which is yet to be initialised in the current scope
    // TODO : TRY TO NOT USE THE BELOW CODE
    // else
    // {
    //     context.createBinding(getId(), getEntity());
    //     stream << "sw " << destReg << " " << context.getOffset(getId())
    //            << "(sp)" << std::endl;
    // }

    // Check local var bindings (TODO)

    return;
}
// Try not to use below method
entity_type Variable::getEntity() const
{
    // return type_;
    return entity_type::VARIABLE;
}

data_type Variable::getType(Context &context) const
{
    return context.getBindingType(getId());
}

data_type Variable::getType() const
{
    // shouldn't go here
    return data_type::_INVALID;
}

std::string Variable::getId() const { return Id_; }
void Variable::setType(entity_type type) { type_ = type; }

void Variable::Print(std::ostream &stream) const { stream << Id_; };
