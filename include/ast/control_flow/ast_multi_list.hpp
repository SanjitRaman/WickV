#ifndef AST_MULTI_LIST_HPP
#define AST_MULTI_LIST_HPP

#include "ast/ast_node.hpp"

class MultiList : public NodeList
{

   public:
    MultiList(NodeList *declaration_list, NodeList *statement_list) : NodeList(declaration_list->getNodes()[0]){
        if (declaration_list->getNodes().size() > 1){
            nodes_.insert(nodes_.end(), declaration_list->getNodes().begin() + 1, declaration_list->getNodes().end());
        }
        nodes_.insert(nodes_.end(), statement_list->getNodes().begin(), statement_list->getNodes().end());
    }

    virtual ~MultiList()
    {}

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
};

#endif