#include "ast_direct_declarator.hpp"

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    identifier_->EmitRISC(stream, context);
    stream << ":" << std::endl;
    
    //Prolog
    context.CreateScope(stream);
    

}

void DirectDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    if (parameter_list_ != nullptr)
    {
        stream << "(";
        parameter_list_->Print(stream);
        stream << ")";
    }
}
