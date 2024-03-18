#ifndef AST_STRING_LITERAL_HPP
#define AST_STRING_LITERAL_HPP

#include "ast/ast_node.hpp"

class StringLiteral : public Node
{
   private:
    std::string string_literal_;

   public:
    StringLiteral(std::string string_literal)
        : string_literal_(string_literal){};
    virtual ~StringLiteral(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual std::string getId() const override;
    virtual entity_type getEntity() const override;
    virtual data_type getType() const override;
    virtual data_type getType(Context &context) const override;
};

#endif