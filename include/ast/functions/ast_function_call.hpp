#ifndef AST_FUNCTION_CALL_HPP
#define AST_FUNCTION_CALL_HPP

#include "ast/ast_node.hpp"
class FunctionCall : public Node
{
   private:
    Node *postfix_expression_;
    NodeList *argument_expression_list_;

   public:
    FunctionCall(Node *postfix_expression, NodeList *argument_expression_list)
        : postfix_expression_(postfix_expression),
          argument_expression_list_(argument_expression_list){};
    FunctionCall(Node *postfix_expression)
        : postfix_expression_(postfix_expression),
          argument_expression_list_(nullptr){};
    virtual ~FunctionCall()
    {
        delete postfix_expression_;
        if (argument_expression_list_ != nullptr)
        {
            delete argument_expression_list_;
        }
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;

    virtual data_type getType(Context &context) const override;
};

#endif
