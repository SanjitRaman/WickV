#ifndef AST_TYPE_SPECIFIER_HPP
#define AST_TYPE_SPECIFIER_HPP

#include "ast/ast_node.hpp"

class TypeSpecifier : public Node
{
   private:
    std::string type_;

   public:
    TypeSpecifier(std::string type) : type_(type){};
    virtual ~TypeSpecifier(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
    virtual data_type getType() const override;
    virtual data_type getType(Context &context) const override;
    virtual std::string getId() const override;
};

#endif
