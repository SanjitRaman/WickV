#include "ast/operators/ast_pointer.hpp"


void Pointer::EmitRISC(std::ostream &stream, Context &context,
                           std::string destReg) const { }

void Pointer::EmitRISC(std::ostream &stream, Context &context) const {

    
}

void Pointer::Print(std::ostream &stream) const
{
    stream << "*";
}

