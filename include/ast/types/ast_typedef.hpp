#ifndef AST_TYPEDEF_HPP
#define AST_TYPEDEF_HPP

#include "ast/ast_node.hpp"

class Typedef : public Node
{
   private:
    std::string identifier_;

   public:
    Typedef(std::string identifier) : identifier_(identifier){};
    virtual ~Typedef(){};
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
    virtual std::string getId() const override;
};

class TypedefDeclaration : public Node
{
   private:
    Node* identifier_; //typedef
    Node* declaration_specifier_; //type_specifier

   public:
    TypedefDeclaration(Node* identifier, Node* declaration_specifier) : identifier_(identifier), declaration_specifier_(declaration_specifier){};
    virtual ~TypedefDeclaration(){
        if (declaration_specifier_ != nullptr){
            delete declaration_specifier_;
        }
        if (identifier_ != nullptr){
            delete identifier_;
        }
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
    virtual std::string getId() const override;
};


#endif
