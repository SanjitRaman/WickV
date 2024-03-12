#include "ast/control_flow/ast_switch_statement.hpp"

void SwitchStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string switch_reg = context.allocateReg(stream);

    // Emit the expression
    context.InitialiseSwitch();

    expression_->EmitRISC(stream, context, switch_reg);

    // Emit the case list
    case_list_->EmitRISC(stream, context, switch_reg);

    context.deallocateReg(switch_reg);
    //put default here
    std::string defaultLabel = context.getDefaultLabel();
    std::string switchLabel = context.getSwitchLabel();
    if (defaultLabel != "")
    {
        stream << "j " << defaultLabel << std::endl;
        context.ExitSwitch(true);
    }
    else{
        context.ExitSwitch(false);
    }
    stream << switchLabel << ":" << std::endl;    

    //end switch here
}

void SwitchStatement::EmitRISC(std::ostream &stream, Context &context,
                               std::string destReg) const
{
}

void SwitchStatement::Print(std::ostream &stream) const
{
    stream << "switch (";
    expression_->Print(stream);
    stream << ") ";
    case_list_->Print(stream);
    stream << std::endl;
}