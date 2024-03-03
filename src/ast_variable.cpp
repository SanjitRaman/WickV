#include "ast_variable.hpp"
void Variable::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << Id_;
}

void Variable::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{
    //This function should move into dest reg and load from memory

    //Check parameter bindings
    if (context.params.find(getId()) != context.params.end()){
        stream << "lw " << destReg << ", " << context.params[getId()].offset << "(sp)"  << std::endl;
    }
    //Check local var bindings
    else if (context.bindings.find(getId()) != context.bindings.end()){
        stream << "lw " << destReg << ", " << context.bindings[getId()].offset << "(sp)"  << std::endl;
    }
    //If the variable is not present in bindings then it must be
    //  a local var which is yet to be initialised in the current scope
    //TRY TO NOT USE THE BELOW CODE 
    else {
        context.createBinding(getId(), getType()); 
        stream << "sw " << destReg << " " << context.bindings.at(getId()).offset << "(sp)" << std::endl;  
    }

    //Check local var bindings (TODO)



    return;

}
//Try not to use below method
entity_type Variable::getType() const {
    // return type_;
    return entity_type::VARIABLE;
}

std::string Variable::getId() const {
    return Id_;
}
void Variable::setType(entity_type type)
{
    type_ = type;
}

void Variable::Print(std::ostream &stream) const
{
    stream << Id_;
};
