#ifndef AST_VARIABLE_HPP
#define AST_VARIABLE_HPP

#include "ast_node.hpp"

class Variable : public Node
{
private:
    std::string Id_;

public:
  Variable(std::string &id_) : Id_(id_){};
  virtual ~Variable(){};
  virtual void EmitRISC(std::ostream &stream, Context &context) const override;
  virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
  virtual void Print(std::ostream &stream) const override;
  virtual std::string getId() const override;
};

#endif
