#include "ast/functions/ast_parameter_list.hpp"

void ParameterList::EmitRISC(std::ostream &stream, Context &context) const
{
    std::unordered_map<std::string, entity_type> params;
    int i = 0;  // keep track of non-float argument registers.
    int j = 0;  // keep track of float argument registers
    std::string offset;
    for (auto param : nodes_)
    {
        if (param == nullptr)
        {
            continue;
        }
        // params[param->getId()] = param->getEntity(); //so we know the offset
        // in compound statement
        offset = context.getMemory(INT_MEM);
        if (param->getType() == data_type::_int)
        {
            stream << "sw a" << i << ", " << offset << "(sp)"
                   << std::endl;  // We know which register to use by order that
                                  // function declares parameters
            i++;
        }
        else if (param->getType() == data_type::_float)
        {
            stream << "fsw.s fa" << j << ", " << offset << "(sp)" << std::endl;
            j++;
        }
        std::cout << "parameter: " << param->getId();
        std::cout << " type: " << param->getEntity() << std::endl;
        if (param->getEntity() == entity_type::POINTER)
        {
            context.update_params(param->getId(), param->getType(), offset,
                                  true);
        }
        else
        {
            context.update_params(param->getId(), param->getType(), offset);
        }
        // node->EmitRISC(stream, context);
    }
}

void ParameterList::EmitRISC(std::ostream &stream, Context &context,
                             std::string destReg) const
{
}
void ParameterList::Print(std::ostream &stream) const
{
    int n = nodes_.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nodes_[i] == nullptr)
        {
            continue;
        }
        nodes_[i]->Print(stream);
        stream << ", ";
    }

    nodes_[n - 1]->Print(stream);
}