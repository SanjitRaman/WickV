#include "ast/control_flow/ast_break.hpp"


void Break::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "break" << std::endl;
    std::cout << "context.getLoopEnd() = " << context.getLoopEnd() << std::endl;
    stream << "j " << context.getLoopEnd() << std::endl;
    
}

void Break::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    //TODO: Check why it goes here
    EmitRISC(stream, context);
    std::cout << "break goes to destreg for some reason" << std::endl;
    
}

void Break::Print(std::ostream &stream) const { 
    stream << "break;";
    stream << std::endl; 
}
