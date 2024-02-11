#ifndef AST_PARAMETER_LIST_HPP
#define AST_PARAMETER_LIST_HPP

#include "ast_node.hpp"

class ParameterDeclarator : public Node
{
private:
    Node* declaration_specifier_;
    Node* declarator_;


public:
  ParameterDeclarator(Node *declaration_specifier, Node *declarator) : declaration_specifier_(declaration_specifier), declarator_(declarator){};
  virtual ~ParameterDeclarator(){};
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void Print(std::ostream &stream) const override;
};

#endif
