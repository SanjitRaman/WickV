#include "ast/control_flow/ast_default.hpp"


void DefaultStatement::EmitRISC(std::ostream &stream, Context &context) const
{
}

void DefaultStatement::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    std::string endDefaultLabel = context.makeLabel("end_default");
    context.setDefaultLabel(); // Set the default statement
    std::string defaultLabel = context.getDefaultLabel();
    stream << "beq zero, zero, " << endDefaultLabel << std::endl;
    stream << defaultLabel << ":" << std::endl;
    statement_->EmitRISC(stream, context);
    stream << "j " << context.getSwitchLabel() << std::endl;
    stream << endDefaultLabel << ":" << std::endl;
}

void DefaultStatement::Print(std::ostream &stream) const { 
    stream << "{}"; 
}
