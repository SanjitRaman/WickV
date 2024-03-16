#include "ast/functions/ast_function_definition.hpp"

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context) const
{
    // Emit assembler directives.
    // TODO: these are just examples ones, make sure you understand
    // the concept of directives and correct them.
    stream << ".text" << std::endl;
    stream << ".globl " << declarator_->getId() << std::endl;

    context.setFunctionReturnType(declarator_->getId(),
                                  declaration_specifiers_->getType());

    declarator_->EmitRISC(stream, context);
    std::string ra_offset = context.getMemory(RA_MEM);
    stream << "sw ra, " << ra_offset << "(sp)" << std::endl;
    if (compound_statement_ != nullptr)
    {
        compound_statement_->EmitRISC(stream, context);
    }
    stream << context.getReturnLabel() << ":" << std::endl;

    // std::cout << "wassup" << std::endl;
    stream << "lw ra, " << ra_offset << "(sp)" << std::endl;
    context.ExitScope(stream);
    stream << "ret" << std::endl;
    // Epilog
    // CreateEpilog();
}

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context,
                                  std::string destReg) const
{
}
void FunctionDefinition::Print(std::ostream &stream) const
{
    declaration_specifiers_->Print(stream);
    stream << " ";

    declarator_->Print(stream);

    if (compound_statement_ != nullptr)
    {
        compound_statement_->Print(stream);
    }
}
