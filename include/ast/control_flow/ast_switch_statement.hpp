#ifndef AST_SWITCH_STATEMENT_HPP
#define AST_SWITCH_STATEMENT_HPP

#include "ast/ast_node.hpp"
#include "ast/control_flow/ast_scope.hpp"
class SwitchStatement : public Node
{
   public:
    SwitchStatement(Node *expression, Node *case_list){
        expression_ = expression;
        case_list_ = dynamic_cast<NodeList *>(case_list);
    };

    virtual ~SwitchStatement()
    {
        delete expression_;
        if (case_list_ != nullptr){
            delete case_list_;
        }
    };

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    entity_type getEntity() const override;

   private:
    Node *expression_;
    NodeList *case_list_;
};

#endif