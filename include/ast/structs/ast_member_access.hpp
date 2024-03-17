#ifndef AST_MEMBER_ACCESS_HPP
#define AST_MEMBER_ACCESS_HPP

#include "ast/ast_node.hpp"

class MemberAccess : public Node
{
   private:
    Node *struct_name_;
    std::string member_name_;

   public:
    MemberAccess(Node *struct_name, std::string member_name)
        : struct_name_(struct_name), member_name_(member_name){};
    virtual ~MemberAccess()
    {
        if (struct_name_ != nullptr)
        {
            delete struct_name_;
        }
    };
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
