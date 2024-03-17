#ifndef AST_SIZEOF_HPP
#define AST_SIZEOF_HPP

#include "ast/ast_node.hpp"

class SizeOf : public Node
{
   private:
    Node *expression_;

   public:
    SizeOf(Node *expression) : expression_(expression){};
    virtual ~SizeOf()
    {
        if (expression_ != nullptr)
        {
            delete expression_;
        }
    }
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
    virtual data_type getType() const override;
    virtual data_type getType(Context &context) const override;
    // virtual std::string getId() const override;
};

#endif
