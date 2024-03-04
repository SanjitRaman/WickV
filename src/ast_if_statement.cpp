#include "ast_if_statement.hpp"

void IfStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string elseLabel = makeName("else");
    std::string endLabel = makeName("end");

    condition_->EmitRISC(stream, context, "t0");
    stream << "beqz $t0, " << elseLabel << std::endl;
    if_statement_->EmitRISC(stream, context);
    stream << "j " << endLabel << std::endl;
    stream << elseLabel << ":" << std::endl;
    for (auto else_if : else_if_statements_)
    {
        else_if->EmitRISC(stream, context);
    }
    if (else_statement_ != nullptr)
    {
        else_statement_->EmitRISC(stream, context);
    }
    stream << endLabel << ":" << std::endl;
}

void IfStatement::Print(std::ostream &stream) const
{
    stream << "if (";
    condition_->Print(stream);
    stream << ") ";
    if_statement_->Print(stream);
    for (auto else_if : else_if_statements_)
    {
        else_if->Print(stream);
    }
    if (else_statement_ != nullptr)
    {
        stream << "else ";
        else_statement_->Print(stream);
    }
}