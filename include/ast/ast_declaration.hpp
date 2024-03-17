#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP

#include "ast/ast_node.hpp"

class Declaration : public Node
{
   private:
    Node *declaration_specifiers_;
    NodeList *init_declaration_list_;

   public:
    Declaration(Node *declaration_specifiers,
                NodeList *init_declaration_list = nullptr)
        : declaration_specifiers_(declaration_specifiers),
          init_declaration_list_(init_declaration_list){};
    virtual ~Declaration()
    {
        delete declaration_specifiers_;
        if (init_declaration_list_ != nullptr)
        {
            delete init_declaration_list_;
        }
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;  // may be overridden
};

#endif
