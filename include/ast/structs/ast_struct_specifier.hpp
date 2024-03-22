#ifndef AST_STRUCT_SPECIFIER_HPP
#define AST_STRUCT_SPECIFIER_HPP

#include "ast/ast_node.hpp"

class StructSpecifier : public Node
{
   private:
    std::string identifier_;
    NodeList *struct_declaration_list_;

   public:
    StructSpecifier(std::string identifier, NodeList *struct_declaration_list)
        : identifier_(identifier),
          struct_declaration_list_(struct_declaration_list){};
    virtual ~StructSpecifier()
    {
        if (struct_declaration_list_ != nullptr)
        {
            delete struct_declaration_list_;
        }
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;  // may be overridden
    virtual std::string getId() const override;
};

#endif
