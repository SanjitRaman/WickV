#include "ast/control_flow/ast_switch_statement.hpp"

void SwitchStatement::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string switch_reg = context.allocateReg(stream);

    // Emit the expression
    context.InitialiseSwitch();

    expression_->EmitRISC(stream, context, switch_reg);

    context.setCaseCond(true);
    for (auto &case_statement : case_list_->getNodes())
    {
        if (case_statement->getEntity() == entity_type::CASE_STATEMENT || case_statement->getEntity() == entity_type::DEFAULT_STATEMENT){
            case_statement->EmitRISC(stream, context, switch_reg);
        }
    }
    if (context.getDefaultLabel() != ""){
        stream << "j " << context.getDefaultLabel()  << std::endl;
    }
    context.setCaseCond(false);
    for (auto &case_statement : case_list_->getNodes())
    {
        case_statement->EmitRISC(stream, context, switch_reg);
    }
    stream << context.getSwitchLabel() << ":" << std::endl;

    std::cout << "I finish emitting all cases" << std::endl;
    context.deallocateReg(switch_reg);
    context.ExitSwitch();

    // end switch here
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

entity_type SwitchStatement::getEntity() const
{
    return entity_type::SWITCH_STATEMENT;
}