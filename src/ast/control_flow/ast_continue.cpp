#include "ast/control_flow/ast_continue.hpp"


void Continue::EmitRISC(std::ostream &stream, Context &context) const
{
    if (context.getLoopUpdate() != "") {
        stream << "j " << context.getLoopUpdate() << std::endl;
    }
    else{
        stream << "j " << context.getLoopStart() << std::endl;
    }
    
}

void Continue::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    EmitRISC(stream, context);
    //TODO: Check if and why this goes here
    
}

void Continue::Print(std::ostream &stream) const { 
    stream << "continue;";
    stream << std::endl; 
}
