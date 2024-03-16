#ifndef AST_ARRAY_INDEX_HPP
#define AST_ARRAY_INDEX_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"
class ArrayIndex : public Node
{
   private:
    Node *identifier_;
    Node *index_;

   public:
    ArrayIndex(Node *identifier, Node *index)
        : identifier_(identifier), index_(index){};
    virtual ~ArrayIndex()
    {
        delete identifier_;
        delete index_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;  // may be overridden
    virtual data_type getType(Context &context) const override;
    virtual std::string getId() const override;
};

#endif
