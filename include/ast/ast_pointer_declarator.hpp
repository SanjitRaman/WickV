#ifndef AST_POINTER_DECLARATOR_HPP
#define AST_POINTER_DECLARATOR_HPP

#include "ast/ast_node.hpp"
class PointerDeclarator : public Node
{
   private:
    Node *pointer_;
    Node *identifier_;

   public:
    PointerDeclarator(Node *pointer, Node *identifier)
        : pointer_(pointer), identifier_(identifier){};
    virtual ~PointerDeclarator()
    {
        delete pointer_;
        delete identifier_;
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
