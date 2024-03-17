#ifndef AST_VARIABLE_HPP
#define AST_VARIABLE_HPP

#include "ast/ast_node.hpp"

class Variable : public Node
{
   private:
    std::string Id_;
    entity_type type_;

   public:
    Variable(std::string &id_, std::string type = "") : Id_(id_)
    {
        std::cout << "Variable created with id: " << Id_ << std::endl;
    };
    virtual ~Variable(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual std::string getId() const override;
    virtual entity_type getEntity() const override;
    virtual data_type getType() const override;
    virtual data_type getType(Context &context) const override;
    // screw this
    void setType(entity_type type);
};

#endif
