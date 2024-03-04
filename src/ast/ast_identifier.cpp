#include "ast/ast_identifier.hpp"

void Identifier::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << identifier_;
}

void Identifier::EmitRISC(std::ostream &stream, Context &context, std::string destReg) const
{

}

void Identifier::Print(std::ostream &stream) const
{
    stream << identifier_;
};
