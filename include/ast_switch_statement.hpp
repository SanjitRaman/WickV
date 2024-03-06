#ifndef AST_SWITCH_STATEMENT_HPP
#define AST_SWITCH_STATEMENT_HPP

#include "ast_context.hpp"
#include "ast_node.hpp"

class SwitchStatement : public Node
{
   public:
    SwitchStatement(Node *expression, Node *case_list)
        : expression_(expression), case_list_(case_list){};

    virtual ~SwitchStatement()
    {
        delete expression_;
        delete case_list_;
    };

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

   private:
    Node *expression_;
    Node *case_list_;
};

#endif