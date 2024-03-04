#ifndef AST_IDENTIFIER_HPP
#define AST_IDENTIFIER_HPP

#include "ast/ast_node.hpp"

class Identifier : public Node
{
private:
    std::string identifier_;

public:
  Identifier(std::string &identifier) : identifier_(identifier){};
  virtual ~Identifier(){};
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
  virtual void Print(std::ostream &stream) const override;
};

#endif
