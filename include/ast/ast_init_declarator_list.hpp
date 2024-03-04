#ifndef AST_INIT_DECLARATOR_LIST_HPP
#define AST_INIT_DECLARATOR_LIST_HPP

#include <iostream>
#include <vector>

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"


class InitDeclaratorList : public NodeList
{

public:
  InitDeclaratorList(Node *first_node) : NodeList(first_node) {}

  virtual ~InitDeclaratorList() {}

  // void PushBack(Node *item);
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
  virtual void Print(std::ostream &stream) const override;
  // std::vector<Node*>& getNodes() const;
    
};

#endif