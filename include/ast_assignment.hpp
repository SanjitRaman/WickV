#ifndef AST_ASSIGNMENT_HPP
#define AST_ASSIGNMENT_HPP

#include "ast_context.hpp"
#include "ast_node.hpp"
class Assignment : public Node
{
   private:
    Node *unary_expression_;
    std::string assignment_operator_;
    Node *assignment_expression_;

   public:
    Assignment(Node *unary_expression, std::string assignment_operator,
               Node *assignment_expression)
        : unary_expression_(unary_expression),
          assignment_operator_(assignment_operator),
          assignment_expression_(assignment_expression)
    {
    }
    virtual ~Assignment()
    {
        delete unary_expression_;
        delete assignment_expression_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
