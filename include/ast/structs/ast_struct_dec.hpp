#ifndef AST_STRUCT_DEC_HPP
#define AST_STRUCT_DEC_HPP

#include "ast/ast_node.hpp"

class StructDec : public Node
{
   private:
    std::string identifier_;

   public:
    StructDec(std::string identifier) : identifier_(identifier){};
    virtual ~StructDec(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;  // may be overridden
    virtual std::string getId() const override;
    virtual data_type getType(Context &context) const override;
};

#endif
