#include "ast/operators/ast_var_assign.hpp"

void VarAssign::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string varReg = context.allocateReg(stream);
    // Assume the binding exists
    if (context.bindings.find(declarator_->getId()) != context.bindings.end())
    {
        // If it is then execute this code
        std::string offset = context.getOffset(declarator_->getId());
        initializer_->EmitRISC(
            stream, context,
            varReg);  // As it is an assignment, it cannot be null
        std::cout << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
        stream << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
    }
    else if (context.params.find(declarator_->getId()) != context.params.end())
    {
        // If it is then execute this code
        std::string offset = context.getOffset(declarator_->getId());
        initializer_->EmitRISC(
            stream, context,
            varReg);  // As it is an assignment, it cannot be null
        std::cout << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
        stream << "sw " << varReg << ", " << offset << "(sp)" << std::endl;
    }
    context.deallocateReg(varReg);
}
void VarAssign::EmitRISC(std::ostream &stream, Context &context,
                         std::string destReg) const
{
    // May not be necessary
    // But if it is then assign the value then move to destReg (maybe call
    // var->emitRISC)
}
entity_type VarAssign::getType() const { return entity_type::VARIABLE_ASSIGN; }

std::string VarAssign::getId() const
{
    return declarator_->getId();  // Shouldn't go here
}

void VarAssign::Print(std::ostream &stream) const {}
// Try not to use below method
//  void VarAssign::setType(entity_type type)
//  {
//   declarator_->setType(type);
//  }