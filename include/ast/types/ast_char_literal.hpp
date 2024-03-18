#ifndef AST_CHAR_LITERAL_HPP
#define AST_CHAR_LITERAL_HPP

#include "ast/ast_node.hpp"

class CharLiteral : public Node
{
   private:
    std::string char_literal_;

   public:
    CharLiteral(std::string char_literal)
        : char_literal_(char_literal){};
    virtual ~CharLiteral(){};
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