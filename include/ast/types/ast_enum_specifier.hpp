#ifndef AST_ENUM_SPECIFIER_HPP
#define AST_ENUM_SPECIFIER_HPP

#include "ast/ast_node.hpp"

class EnumSpecifier : public Node
{
   private:
    std::string identifier_;
    NodeList* enumerator_list_;

   public:
    EnumSpecifier(std::string identifier, NodeList* enumerator_list) : identifier_(identifier), enumerator_list_(enumerator_list){};
    virtual ~EnumSpecifier(){
        if (enumerator_list_ != nullptr){
            delete enumerator_list_;
        }
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType() const override;
    virtual std::string getId() const override;
};

#endif
