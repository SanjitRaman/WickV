#include "ast_function_definition.hpp"

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context) const
{
    // TODO: this is not complete.
    std::cerr << "FunctionDefinition: EmitRISC is not fully implemented." << std::endl;

    // Emit assembler directives.
    // TODO: these are just examples ones, make sure you understand
    // the concept of directives and correct them.
    stream << ".text" << std::endl;
    stream << ".globl f" << std::endl;

    declarator_->EmitRISC(stream, context);

    if (compound_statement_ != nullptr)
    {
        compound_statement_->EmitRISC(stream, context);
    }
}

void FunctionDefinition::Print(std::ostream &stream) const
{
    // TODO: this is not complete.
    std::cerr << "FunctionDefinition: Print is not fully implemented." << std::endl;

    declaration_specifiers_->Print(stream);
    stream << " ";

    declarator_->Print(stream);
    stream << "() {" << std::endl;

    if (compound_statement_ != nullptr)
    {
        compound_statement_->Print(stream);
    }
    stream << "}" << std::endl;
}
