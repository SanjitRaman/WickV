#ifndef AST_PARAMETER_DECLARATOR_HPP
#define AST_PARAMETER_DECLARATOR_HPP

#include "ast_node.hpp"

class ParameterDeclarator : public Node
{
private:
    Node* declaration_specifier_;
    Node* declarator_;


public:
  ParameterDeclarator(Node *declaration_specifier, Node *declarator) : declaration_specifier_(declaration_specifier), declarator_(declarator){};
  virtual ~ParameterDeclarator(){
    delete declaration_specifier_;
    delete declarator_;
  };
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
  virtual void Print(std::ostream &stream) const override;
  virtual entity_type getType() const override; //may be overridden
  virtual std::string getId() const override;
};

#endif
