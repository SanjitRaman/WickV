#ifndef AST_PARAMETER_LIST_HPP
#define AST_PARAMETER_LIST_HPP

#include "ast_node.hpp"

class ParameterDeclarator : public Node
{
private:
    Node* type_specifier_;
    Node* declarator_;


public:
  ParameterDeclarator(Node *type_specifier, Node *declarator) : type_specifier_(type_specifier), declarator_(declarator){};
  ~ParameterDeclarator(){};
  void EmitRISC(std::ostream &stream, Context &context) const override;
  void Print(std::ostream &stream) const override;
};

#endif
