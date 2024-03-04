#ifndef AST_VAR_ASSIGN_HPP
#define AST_VAR_ASSIGN_HPP

#include "ast_context.hpp"
#include "ast_node.hpp"

class VarAssign : public Node
{
   private:
    Node *declarator_;
    Node *initializer_;

   public:
    VarAssign(Node *declarator_, Node *initializer_)
        : declarator_(declarator_), initializer_(initializer_){};
    virtual ~VarAssign()
    {
        delete declarator_;
        delete initializer_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType()
        const override;  // may be overridden (return declarator_->getType())
    virtual std::string getId()
        const override;  // may be overridden (return declarator_->getId()) but
                         // shouldn't be necessary
    // void setType(entity_type type);
};

#endif
