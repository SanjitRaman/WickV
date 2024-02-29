#include "ast_variable.hpp"

void Variable::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{
    //This function should move into dest reg and load from memory

    //Check parameter bindings
    if (context.params.find(getId()) != context.params.end()){
        stream << "lw " << destReg << ", (sp)" << context.params[getId()].offset << std::endl;
    }
    else if (context.bindings.find(getId()) != context.bindings.end()){
        stream << "lw " << destReg << ", (sp)" << context.bindings[getId()].offset << std::endl;
    }
    else {}

    //Check local var bindings (TODO)



    return;

}

std::string Variable::getId() const {
    return Id_
}

void Variable::Print(std::ostream &stream) const
{
    stream << identifier_;
};
