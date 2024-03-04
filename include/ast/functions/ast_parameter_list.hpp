#ifndef AST_PARAMETER_LIST_HPP
#define AST_PARAMETER_LIST_HPP

#include <iostream>
#include <vector>

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"


class ParameterList : public NodeList
{

public:
  ParameterList(Node *first_node) : NodeList(first_node) {}

  virtual ~ParameterList() {}

  // void PushBack(Node *item);
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
  virtual void Print(std::ostream &stream) const override;
    
};

#endif