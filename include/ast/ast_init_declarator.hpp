#ifndef AST_DECLARATOR_HPP
#define AST_DECLARATOR_HPP

#include "ast/ast_node.hpp"

class InitDeclarator : public Node
{
   private:
    Node *declarator_;

   public:
    InitDeclarator(Node *declarator) : declarator_(declarator){};
    virtual ~InitDeclarator() { delete declarator_; };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType() const override;  // may be overridden
    virtual std::string getId() const override;
};

#endif
