#ifndef AST_STATEMENTS_HPP
#define AST_STATEMENTS_HPP

#include "ast_node.hpp"

class ReturnStatement : public Node
{
private:
    Node *expression_;

public:
    ReturnStatement(Node *expression) : expression_(expression) {}
    ~ReturnStatement()
    {
        delete expression_;
    };

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
};

#endif
