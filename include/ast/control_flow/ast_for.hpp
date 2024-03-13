#ifndef AST_FOR_STATEMENT_HPP
#define AST_FOR_STATEMENT_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

class ForStatement : public Node
{
   private:
    Node *start_;
    Node *loop_condition_;
    Node *increment_;
    Node *for_statement_;

   public:
    ForStatement(Node *start, Node *loop_condition, Node* increment, Node* for_statement)
        : start_(start), loop_condition_(loop_condition), increment_(increment), for_statement_(for_statement)  {};
    ForStatement(Node *start, Node *loop_condition, Node* for_statement)
        : start_(start), loop_condition_(loop_condition), increment_(nullptr), for_statement_(for_statement)  {};
    
    virtual ~ForStatement()
    {
        delete start_;
        delete loop_condition_;
        if (increment_ != nullptr){
            delete increment_;
        }
        delete for_statement_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif