#ifndef AST_CASE_HPP
#define AST_CASE_HPP

#include "ast/ast_node.hpp"

class CaseStatement : public Node
{
   public:
    CaseStatement(Node *expression, Node *statement)
        : expression_(expression), statement_(statement){};

    virtual ~CaseStatement()
    {
        delete expression_;
        delete statement_;
    }

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    entity_type getEntity() const override;

   private:
    Node *expression_;
    Node *statement_;
};
#endif