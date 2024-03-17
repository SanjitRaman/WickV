#ifndef AST_STRUCT_DECLARATOR_LIST_HPP
#define AST_STRUCT_DECLARATOR_LIST_HPP

#include <iostream>
#include <vector>

#include "ast/ast_node.hpp"

class StructDeclaratorList : public NodeList
{
   public:
    StructDeclaratorList(Node *first_node) : NodeList(first_node) {}
    virtual ~StructDeclaratorList() {}
    virtual std::string getId() const override;
};
#endif