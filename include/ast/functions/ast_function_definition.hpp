#ifndef AST_FUNCTION_DEFINITION_HPP
#define AST_FUNCTION_DEFINITION_HPP

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"
class FunctionDefinition : public Node
{
   private:
    Node *declaration_specifiers_;
    Node *declarator_;
    Node *compound_statement_;

   public:
    FunctionDefinition(Node *declaration_specifiers, Node *declarator,
                       Node *compound_statement)
        : declaration_specifiers_(declaration_specifiers),
          declarator_(declarator),
          compound_statement_(compound_statement){};
    virtual ~FunctionDefinition()
    {
        delete declaration_specifiers_;
        delete declarator_;
        delete compound_statement_;
    };
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
};

#endif
