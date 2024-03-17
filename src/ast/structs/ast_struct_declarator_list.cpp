#include "ast/structs/ast_struct_declarator_list.hpp"

std::string StructDeclaratorList::getId() const
{
    std::string id;
    for (auto node : getNodes())
    {
        id += node->getId() + ",";
    }
    id = id.substr(0, id.length() - 1);
}