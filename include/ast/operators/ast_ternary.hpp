#ifndef AST_TERNARY_HPP
#define AST_TERNARY_HPP

#include "ast/ast_node.hpp"

// ---------------------- Ternary ----------------------
class Ternary : public Node
{
   private:
    Node *condition_;
    Node *true_expression_;
    Node *false_expression_;

   public:
    Ternary(Node *condition, Node *true_expression, Node* false_expression) : condition_(condition), true_expression_(true_expression), false_expression_(false_expression){};
    virtual ~Ternary()
    {
        delete condition_;
        delete true_expression_;
        delete false_expression_;
    };
    // Do we need an evaluate?
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual data_type getType(Context &context) const override;
};

#endif