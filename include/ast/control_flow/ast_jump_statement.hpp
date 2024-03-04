#ifndef AST_JUMP_STATEMENT_HPP
#define AST_JUMP_STATEMENT_HPP

#include "ast/control_flow/ast_jump_statement.hpp"

class ReturnStatement : public Node
{
private:
    Node *expression_;

public:
    ReturnStatement(Node *expression) : expression_(expression) {}
    virtual ~ReturnStatement()
    {
        delete expression_;
    };

    virtual void EmitRISC(std::ostream &stream, Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
