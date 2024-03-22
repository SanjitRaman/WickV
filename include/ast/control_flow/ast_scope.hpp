#ifndef AST_SCOPE_HPP
#define AST_SCOPE_HPP

#include "ast/ast_node.hpp"

class Scope : public NodeList
{
    private:
     NodeList *code_list;

   public:
    Scope(NodeList *code_list) : NodeList(code_list->getNodes()[0]), code_list(code_list)
    {
        if (code_list->getNodes().size() > 1){
            nodes_.insert(nodes_.end(), code_list->getNodes().begin() + 1, code_list->getNodes().end());
        }
    }

    virtual ~Scope(){
        if (code_list != nullptr)
        {
            delete code_list;
        }
    }
    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
};

#endif