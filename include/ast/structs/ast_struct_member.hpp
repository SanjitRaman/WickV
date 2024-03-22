#ifndef AST_STRUCT_MEMBER_HPP
#define AST_STRUCT_MEMBER_HPP

#include "ast/ast_node.hpp"

class StructMember : public Node
{
   private:
    Node *specifier_qualifier_list_;
    Node *struct_declarator_list_;

   public:
    StructMember(Node *specifier_qualifier_list, Node *struct_declarator_list)
        : specifier_qualifier_list_(specifier_qualifier_list),
          struct_declarator_list_(struct_declarator_list){};
    virtual ~StructMember()
    {
        delete specifier_qualifier_list_;
        delete struct_declarator_list_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    // virtual entity_type getEntity() const override;  // may be overridden
    virtual std::string getId() const override;
    virtual data_type getType()
        const override;  // Shouldn't need one with context
};

#endif
