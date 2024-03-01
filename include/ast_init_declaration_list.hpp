#ifndef AST_INIT_DECLARATION_LIST_HPP
#define AST_INIT_DECLARATION_LIST_HPP

#include <iostream>
#include <vector>

#include "ast_context.hpp"
#include "ast_node.hpp"


class InitDeclarationList : public NodeList
{

public:
  InitDeclarationList(Node *first_node) : NodeList(first_node) {}

  ~InitDeclarationList() {}

  // void PushBack(Node *item);
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
  virtual void Print(std::ostream &stream) const override;
    
};

#endif