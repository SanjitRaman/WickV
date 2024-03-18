#include "ast/ast_array_index.hpp"

void ArrayIndex::EmitRISC(std::ostream &stream, Context &context) const {}

void ArrayIndex::EmitRISC(std::ostream &stream, Context &context,
                          std::string destReg) const
{
    if (context.getIsPointer(getId()))
    {
        if (context.getBindingType(getId()) == data_type::_char){
            std::string index_reg = context.allocateReg(stream);
            index_->EmitRISC(stream, context, index_reg);
            context.getOffset(getId());
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                   << "(sp)" << std::endl;
            stream << "add " << index_reg << ", " << destReg << ", " << index_reg
                     << std::endl;
            stream << "lbu " << destReg << ", 0(" << index_reg << ")" << std::endl;
            context.deallocateReg(index_reg); 
        }
        else {
            std::string index_reg = context.allocateReg(stream);
            index_->EmitRISC(stream, context, index_reg);
            stream << "li " << destReg << ", " << INT_MEM << std::endl;
            stream << "mul " << index_reg << ", " << index_reg << ", " << destReg
                << std::endl;
            stream << "lw " << destReg << ", " << context.getOffset(getId())
                << "(sp)" << std::endl;
            stream << "add " << index_reg << ", " << destReg << ", " << index_reg
                << std::endl;
            stream << "lw " << destReg << ", 0(" << index_reg << ")" << std::endl;
            // TODO: Check if we need to setIndexReg in context
            context.deallocateReg(index_reg);

        }
        
    }
    else
    {
        std::string start_offset = context.getOffset(getId());
        std::string index_reg = context.allocateReg(stream);
        // In context, use a setIndexReg and getIndexReg to keep track of it,
        // and if we need it in the first place
        index_->EmitRISC(stream, context, index_reg);
        // TODO: other if branches for other data_types
        if (context.getBindingType(getId()) == data_type::_int)
        {
            stream << "li " << destReg << ", " << INT_MEM << std::endl;
            stream << "mul " << index_reg << ", " << index_reg << ", "
                   << destReg << std::endl;
        }
        stream << "li " << destReg << ", " << start_offset << std::endl;
        stream << "sub " << destReg << ", " << destReg << ", " << index_reg
               << std::endl;
        stream << "add " << destReg << ", " << destReg << ", sp" << std::endl;
        stream << "mv " << index_reg << ", " << destReg << std::endl;
        stream << "lw " << destReg << ", 0(" << index_reg << ")" << std::endl;

        if (context.getFetchIndexReg())
        {
            context.setIndexReg(index_reg);
        }
        else
        {
            context.deallocateReg(index_reg);
        }
    }
}

entity_type ArrayIndex::getEntity() const { return entity_type::ARRAY; }

std::string ArrayIndex::getId() const { return identifier_->getId(); }

void ArrayIndex::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    stream << "[";
    index_->Print(stream);
    stream << "]";
}

data_type ArrayIndex::getType(Context &context) const
{
    return context.getBindingType(getId());
}