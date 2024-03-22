#include "ast/types/ast_sizeof.hpp"

void SizeOf::EmitRISC(std::ostream &stream, Context &context) const {}

void SizeOf::EmitRISC(std::ostream &stream, Context &context,
                      std::string destReg) const
{
    data_type type = expression_->getType(context);
    if (type == data_type::_int)
    {
        stream << "li " << destReg << ", " << INT_MEM << std::endl;
    }
    else if (type == data_type::_float)
    {
        stream << "li " << destReg << ", " << FLOAT_MEM << std::endl;
    }
    else if (type == data_type::_double)
    {
        stream << "li " << destReg << ", " << DOUBLE_MEM << std::endl;
    }
    else if (type == data_type::_char)
    {
        stream << "li " << destReg << ", " << CHAR_MEM << std::endl;
    }
    // URGENT TODO: implement all types
    // else if (type == data_type::_unsigned)
    // {
    //     stream << "li " << destReg << ", " << UNSIGNED_MEM << std::endl;
    // }
    else
    {
        // TODO: sus
        stream << "li " << destReg << ", " << INT_MEM << std::endl;
    }
}

void SizeOf::Print(std::ostream &stream) const
{
    stream << "sizeof(";
    expression_->Print(stream);
    stream << ")";
}

entity_type SizeOf::getEntity() const { return entity_type::SIZE_OF; }

data_type SizeOf::getType() const { return data_type::_int; }

data_type SizeOf::getType(Context &context) const { return data_type::_int; }