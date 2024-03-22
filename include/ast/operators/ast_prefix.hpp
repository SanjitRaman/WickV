#ifndef AST_PREFIX_HPP
#define AST_PREFIX_HPP

#include "ast/ast_node.hpp"

class PrefixOperator : public Node
{
   private:
    Node *primary_expression_;
    std::string op_;

   public:
    PrefixOperator(Node *primary_expression, std::string op)
        : primary_expression_(primary_expression), op_(op){};
    virtual ~PrefixOperator() { delete primary_expression_; };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

#endif