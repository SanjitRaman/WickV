#ifndef AST_TYPE_SPECIFIER
#define AST_TYPE_SPECIFIER

#include "ast/ast_node.hpp"

class TypeSpecifier : public Node
{
private:
    std::string type_;

public:
    TypeSpecifier(std::string type) : type_(type){};
    virtual ~TypeSpecifier(){};
    virtual void EmitRISC(std::ostream &stream, Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context, std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType() const override;
    virtual std::string getId() const override;
};

#endif
