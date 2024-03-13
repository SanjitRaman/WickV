#include "ast/ast_array_index.hpp"

void ArrayIndex::EmitRISC(std::ostream &stream, Context &context) const
{ 
}

void ArrayIndex::EmitRISC(std::ostream &stream, Context &context,
                                std::string destReg) const
{
    std::string start_offset = context.getOffset(getId());
    std::string index_reg = context.allocateReg(stream);
    //In context, use a setIndexReg and getIndexReg to keep track of it, and if we need it in the first place
    index_->EmitRISC(stream, context, index_reg);
    if (context.getBindingType(getId()) == entity_type::INTEGER)
    {
        
        stream << "li " << destReg << ", " << INT_MEM << std::endl;
        stream << "mul " << index_reg << ", " << index_reg << ", " << destReg << std::endl;
    }
    stream << "li " << destReg << ", " << start_offset << std::endl;
    stream << "sub " << destReg << ", " << destReg << ", " << index_reg << std::endl;
    stream << "add " << destReg << ", " << destReg << ", sp" << std::endl;
    stream << "mv " << index_reg << ", " << destReg << std::endl;
    stream << "lw " << destReg << ", 0(" << index_reg << ")" << std::endl;
    
    if (context.getFetchIndexReg()){
        context.setIndexReg(index_reg);
    }
    else{
        context.deallocateReg(index_reg);
    }
}



entity_type ArrayIndex::getType() const { return entity_type::ARRAY; }

std::string ArrayIndex::getId() const { return identifier_->getId(); }

void ArrayIndex::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    stream << "[";
    index_->Print(stream);
    stream << "]";
}
