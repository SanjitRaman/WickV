#ifndef AST_ENUMERATOR_HPP
#define AST_ENUMERATOR_HPP

#include "ast/ast_node.hpp"

class Enumerator : public Node
{
   private:
    std::string identifier_;
    Node* constant_expression_;

   public:
    Enumerator(std::string identifier, Node* constant_expression) : identifier_(identifier), constant_expression_(constant_expression){};
    Enumerator(std::string identifier) : identifier_(identifier){};
    virtual ~Enumerator(){
        if (constant_expression_ != nullptr)
        {
            delete constant_expression_;
        }
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getType() const override;
    virtual std::string getId() const override;
    //TODO: Do we need getValue()
};

#endif
