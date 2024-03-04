#include "ast_function_definition.hpp"

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context) const
{
    // Emit assembler directives.
    // TODO: these are just examples ones, make sure you understand
    // the concept of directives and correct them.
    stream << ".text" << std::endl;
    stream << ".globl " << declarator_->getId() << std::endl;
    
    
    declarator_->EmitRISC(stream, context);


    if (compound_statement_ != nullptr)
    {
        compound_statement_->EmitRISC(stream, context);
    }
    stream << context.getReturnLabel() << ":" << std::endl;

    // std::cout << "wassup" << std::endl;
    context.ExitScope(stream);

    stream << "ret" << std::endl;
    // Epilog
    // CreateEpilog();
}

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}
void FunctionDefinition::Print(std::ostream &stream) const
{
    declaration_specifiers_->Print(stream);
    stream << " ";

    declarator_->Print(stream);
    stream << " {" << std::endl;

    if (compound_statement_ != nullptr)
    {
        compound_statement_->Print(stream);
    }
    stream << "}" << std::endl;
}
