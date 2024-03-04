#ifndef AST_MULTI_LIST_HPP
#define AST_MULTI_LIST_HPP

#include "ast/ast_node.hpp"

class MultiList : public Node
{
protected:
    NodeList* declaration_list_;
    NodeList* statement_list_;

public:
    // MultiList(NodeList *declaration_list,  NodeList* statement_list) : declaration_list_(declaration_list), statement_list_(statement_list) {}
    MultiList(NodeList *declaration_list,  NodeList* statement_list);

    ~MultiList()
    {
        delete declaration_list_;
        delete statement_list_;
    }

    virtual void EmitRISC(std::ostream &stream, Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override; 
};

#endif