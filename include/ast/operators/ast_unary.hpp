#ifndef AST_UNARY_HPP
#define AST_UNARY_HPP

#include "ast/ast_node.hpp"

class Unary : public Node
{
   private:
    std::string unary_op_;
    Node *cast_expression_;

   public:
    Unary(std::string unary_op, Node *cast_expression)
        : unary_op_(unary_op), cast_expression_(cast_expression){};
    virtual ~Unary()
    {
        delete cast_expression_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType()
        const override;  // may be overridden (return declarator_->getType())
    virtual std::string getId()
        const override;  // may be overridden (return declarator_->getId()) but
                         // shouldn't be necessary
    // void setType(entity_type type);
};

#endif
