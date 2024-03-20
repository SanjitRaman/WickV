#include "ast/control_flow/ast_default.hpp"


void DefaultStatement::EmitRISC(std::ostream &stream, Context &context) const
{
}

void DefaultStatement::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    if (context.getCaseCond()){
        context.setDefaultLabel();
    }
    else{
        std::string default_label = context.getDefaultLabel();
        stream << default_label << ":" << std::endl;
        statement_->EmitRISC(stream, context);
    }
}

void DefaultStatement::Print(std::ostream &stream) const { 
    stream << "default: ";
    statement_->Print(stream);
    stream << std::endl;
}

entity_type DefaultStatement::getEntity() const
{
    return entity_type::DEFAULT;
}