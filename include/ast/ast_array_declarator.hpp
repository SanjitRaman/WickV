#ifndef AST_ARRAY_DECLARATOR_HPP
#define AST_ARRAY_DECLARATOR_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"
class ArrayDeclarator : public Node
{
   private:
    Node *identifier_;
    Node *size_;

   public:
    ArrayDeclarator(Node *identifier, Node *size)
        : identifier_(identifier), size_(size){};
    virtual ~ArrayDeclarator()
    {
        delete identifier_;
        delete size_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType() const override;  // may be overridden
    virtual std::string getId() const override;
};

#endif
