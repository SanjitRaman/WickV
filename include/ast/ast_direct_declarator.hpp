#ifndef AST_DIRECT_DECLARATOR_HPP
#define AST_DIRECT_DECLARATOR_HPP

#include "ast/ast_node.hpp"

// Exclusively used for functions
class DirectDeclarator : public Node
{
   private:
    Node *identifier_;
    Node *parameter_list_;

   public:
    DirectDeclarator(Node *identifier, Node *parameter_list = nullptr)
        : identifier_(identifier), parameter_list_(parameter_list){};
    virtual ~DirectDeclarator()
    {
        delete identifier_;
        if (parameter_list_ != nullptr)
        {
            delete parameter_list_;
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
