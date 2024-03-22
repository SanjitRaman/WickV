#ifndef AST_MULTI_LIST_HPP
#define AST_MULTI_LIST_HPP

#include "ast/ast_node.hpp"

class MultiList : public NodeList
{
    private:
     NodeList *declaration_list_;
     NodeList *statement_list_;

   public:
    MultiList(NodeList *declaration_list, NodeList *statement_list) : NodeList(declaration_list->getNodes()[0]), declaration_list_(declaration_list), statement_list_(statement_list)
    {
        if (declaration_list_->getNodes().size() > 1){
            nodes_.insert(nodes_.end(), declaration_list_->getNodes().begin() + 1, declaration_list_->getNodes().end());
        }
        nodes_.insert(nodes_.end(), statement_list_->getNodes().begin(), statement_list_->getNodes().end());
    }

    virtual ~MultiList()
    {
        delete declaration_list_;
        delete statement_list_;
    }

    virtual void EmitRISC(std::ostream &stream,
                          Context &context) const override;
    virtual void EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const override;
    virtual void Print(std::ostream &stream) const override;
    virtual entity_type getEntity() const override;
};

#endif