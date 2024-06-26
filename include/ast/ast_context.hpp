#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "ast/types/ast_entity_type.hpp"
// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).

// Stores

struct switch_properties
{
    std::string switch_label;
    std::string default_label;
    std::vector<std::string> case_labels;
    bool emit_cond;
};

struct loop_labels
{
    std::string startLabel;
    std::string updateLabel;
    std::string endLabel;
};

struct variable
{
    std::string offset;
    data_type type;
    bool isPointer;
};

struct enum_vals
{
    std::string id;
    std::unordered_map<std::string, int>
        enum_vals;  // May not need to store in context
};

struct param
{
    std::string offset;
    data_type type;
    bool isPointer;
};
// Scope : store local var bindings in the memory scope

struct reg_file
{
    int Regs[32] = {
        1,        // x0            zero        Zero
        1,        // x1            ra          Return address
        1,        // x2            sp          Stack pointer
        1,        // x3            gp          Global pointer
        1,        // x4            tp          Thread pointer
        0, 0, 0,  // x5 - x7       t0 - t2     Temporary registers
        1, 1,     // x8 - x9       s0 - s1     Callee-saved registers
        1, 1, 1, 1, 1, 1, 1, 1,  // x10 - x17     a0 - a7     Argument registers
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 1,       // x18 - x27     s2 - s11    Callee-saved registers
        0, 0, 0, 0  // x28 - x31     t3 - t6     Temporary registers
    };

    void setReg(int reg, int val)
    {  // Val should be 0 or 1
        Regs[reg] = val;
    }
    int getReg(int reg) { return Regs[reg]; }
};

struct float_reg_file
{
    // TODO: Check if the float registers are correct
    int Regs_floats[32] = {
        0,        // f0
        0,        // f1
        0,        // f2
        0,        // f3            gp          Global pointer
        0,        // f4            tp          Thread pointer
        0, 0, 0,  // f5 - f7       t0 - t2     Temporary registers
        1, 1,     // f8 - f9       s0 - s1     Callee-saved registers
        1, 1, 1, 1, 1, 1, 1, 1,  // f10 - f17     a0 - a7     Argument registers
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,       // f18 - f27     s2 - s11    Callee-saved registers
        0, 0, 0, 0  // f28 - f31     t3 - t6     Temporary registers
    };

    void setFloatReg(int reg, int val) { Regs_floats[reg] = val; }

    int getFloatReg(int reg) { return Regs_floats[reg]; }
};

class Context
{
   protected:
    reg_file risc_regs;
    float_reg_file risc_float_regs;

    int makeLabelUnq = 0;
   public:
    std::vector<std::unordered_map<std::string, variable>>
        scopes;                                     // Stores symbol tables
    std::unordered_map<std::string, param> params;  // Clear params in exit
                                                    // scope
    std::vector<std::unordered_map<std::string, param>>
        param_stack;  // Stores function parameters
    std::unordered_map<std::string, data_type> function_return_types;
    std::vector<std::string> return_branches;
    std::vector<int> remaining_mem_stack;
    std::unordered_map<std::string, variable>
        bindings;  // Bindings (Local variables) for current scope
    std::vector<switch_properties> switch_info;
    std::vector<loop_labels> loop_info;
    std::vector<std::vector<std::string>> savedRegs;  // For function calls

    // Strings
    std::unordered_map<std::string, std::string> string_headers;

    bool fetchArrayIndex = false;
    std::string ArrayIndexReg = "";

    // Enum
    int global_enum_val = -1;
    std::vector<enum_vals> enum_info;

    // Struct
    std::unordered_map<std::string, std::unordered_map<std::string, data_type>>
        struct_info;

    int frame_size = 128;            // Size of stack frame
    int remaining_mem = frame_size;  // Offset

    std::string makeLabel(std::string base)
    {
        return "_" + base + "_" + std::to_string(makeLabelUnq++);
    }
    // For loops
    void createLoop(std::string start, std::string end, std::string update)
    {
        loop_labels new_loop;
        new_loop.startLabel = start;
        new_loop.endLabel = end;
        new_loop.updateLabel = update;
        loop_info.push_back(new_loop);
    }

    // While loops
    void createLoop(std::string start, std::string end)
    {
        loop_labels new_loop;
        new_loop.startLabel = start;
        new_loop.updateLabel = "";
        new_loop.endLabel = end;
        loop_info.push_back(new_loop);
    }
    std::string getLoopStart() { return loop_info.back().startLabel; }
    std::string getLoopEnd() { return loop_info.back().endLabel; }

    std::string getLoopUpdate() { return loop_info.back().updateLabel; }

    void exitLoop() { loop_info.pop_back(); }

    void InitialiseSwitch()
    {
        std::string switch_label = makeLabel("end_switch");
        switch_properties new_switch;
        new_switch.switch_label = switch_label;
        new_switch.default_label = "";
        new_switch.emit_cond = false;
        switch_info.push_back(new_switch);
        loop_labels new_switch_loop;
        new_switch_loop.startLabel = "";
        new_switch_loop.updateLabel = "";
        new_switch_loop.endLabel = switch_label;
        loop_info.push_back(new_switch_loop);
    }
    void setDefaultLabel(){
        switch_info.back().default_label = makeLabel("default_statement");
    }

    std::string getDefaultLabel(){
        return switch_info.back().default_label;
    }

    std::string setCaseLabel()
    {
        std::string case_label = makeLabel("case_statement");
        switch_info.back().case_labels.push_back(case_label);
        return case_label;
    }

    std::string getCaseLabel() {
        std::string case_label = switch_info.back().case_labels[0];
        switch_info.back().case_labels.erase(switch_info.back().case_labels.begin());
        return case_label;
    }

    std::string getSwitchLabel() { return switch_info.back().switch_label; }

    void setCaseCond(bool emit_cond){
        switch_info.back().emit_cond = emit_cond;
    }

    bool getCaseCond(){
        return switch_info.back().emit_cond;
    }

    void ExitSwitch()
    {
        switch_info.pop_back();
        loop_info.pop_back();
    }

    

    // Enum
    void createEnum(std::string id)
    {
        enum_vals new_enum;
        new_enum.id = id;
        enum_info.push_back(new_enum);
    }

    int setEnumVal()
    {
        bool found = true;
        global_enum_val++;
        while (found){
            found = false;
            for (auto const& pair : enum_info.back().enum_vals)
            {
                if (pair.second == global_enum_val){
                    found = true;
                    global_enum_val++;
                    break;
                }
            }
        }
        return global_enum_val;
    }

    void resetEnumVal() { global_enum_val = -1; }

    void addEnumVal(std::string id, int val)
    {
        enum_info.back().enum_vals[id] = val;
    }

    int getEnumVal(std::string id)
    {
        for (auto enum_specifier : enum_info)
        {
            if (enum_specifier.enum_vals.find(id) !=
                enum_specifier.enum_vals.end())
            {
                return enum_specifier.enum_vals[id];
            }
        }
        return -1;
    }


    void update_params(std::string param_name, data_type param_type,
                       std::string param_offset, bool isPointer = false)
    {
        param new_param;
        new_param.type = param_type;
        new_param.offset = param_offset;
        new_param.isPointer = isPointer;
        params[param_name] = new_param;

    } 


    std::string getMemory(int mem_size)
    {
        if (remaining_mem == 0)
        {
            return "";  // ERROR
        }
        else
        {
            remaining_mem -= mem_size;
            return std::to_string(remaining_mem);
        }
    }

    void deallocateMemory(int mem_size) { remaining_mem += mem_size; }

    void addArray(std::string id, int array_size)
    {
        std::string offset;
        // Binding created in InitDeclarator/Declaration
        if (bindings[id].type == data_type::_int)
        {
            for (int i = 0; i < array_size - 1; i++)
            {
                offset =
                    getMemory(INT_MEM); 
            }
        }
        else if (bindings[id].type == data_type::_float)
        {
            for (int i = 0; i < array_size - 1; i++)
            {
                offset = getMemory(FLOAT_MEM);
            }
        }
        else if (bindings[id].type == data_type::_double)
        {
            for (int i = 0; i < array_size - 1; i++)
            {
                offset = getMemory(DOUBLE_MEM);
            }
        }
        else if (bindings[id].type == data_type::_char)
        {
            for (int i = 0; i < array_size - 1; i++)
            {
                offset = getMemory(CHAR_MEM);
            }
        }
        else
        {
            for (int i = 0; i < array_size - 1; i++)
            {
                offset = getMemory(INT_MEM);  // Default, but shouldn't need
            }
        }
    }
    void setFetchIndexReg(bool shouldFetch)
    {
        fetchArrayIndex = shouldFetch;
        // If shouldFetch is true, then fetch the array index
        // If shouldFetch is false, then don't fetch the array index
    }

    bool getFetchIndexReg() { return fetchArrayIndex; }

    void setIndexReg(std::string index_reg) { ArrayIndexReg = index_reg; }

    std::string getIndexReg()
    {
        return ArrayIndexReg;
        // TODO: Maybe reset ArrayIndexReg to "" after use of this method???
    }

    void createBinding(std::string id, data_type type, bool isPointer = false)
    {
        std::cout << "Creating binding for " << id << std::endl;
        std::cout << isPointer << std::endl;
        std::string offset;
        if (type == data_type::_int)
        {
            offset = getMemory(INT_MEM);
        }
        else if (type == data_type::_float)
        {
            offset = getMemory(FLOAT_MEM);
        }
        else if (type == data_type::_double)
        {
            offset = getMemory(DOUBLE_MEM);
        }
        else if (type == data_type::_char && isPointer)
        {
            offset = getMemory(INT_MEM);
        }
        else if (type == data_type::_char && !isPointer)
        {
            offset = getMemory(CHAR_MEM);
        }
        else
        {
            offset = getMemory(INT_MEM);  // Default, but shouldn't need
        }
        variable newVar;
        newVar.offset = offset;
        newVar.type = type;
        newVar.isPointer = isPointer;
        bindings[id] = newVar;
    }

    std::string getOffset(std::string id)
    {
        if (params.find(id) != params.end())
        {
            return params[id].offset;
        }
        else if (bindings.find(id) != bindings.end())
        {
            return bindings[id].offset;
        }
        for (auto scope = scopes.rbegin(); scope != scopes.rend(); ++scope)
        {
            if ((*scope).find(id) != (*scope).end())
            {
                return (*scope)[id].offset;
            }
        }
        return "null";
    }

    bool getIsPointer(std::string id)
    {
        if (params.find(id) != params.end())
        {
            return params[id].isPointer;
        }
        if (bindings.find(id) != bindings.end())
        {
            return bindings[id].isPointer;
        }
        for (auto scope = scopes.rbegin(); scope != scopes.rend(); ++scope)
        {
            if ((*scope).find(id) != (*scope).end())
            {
                return (*scope)[id].isPointer;
            }
        }
        return false;
    }

    data_type getBindingType(std::string id)
    {
        if (params.find(id) != params.end())
        {
            return params[id].type;
        }
        if (bindings.find(id) != bindings.end())
        {
            return bindings[id].type;
        }
        for (auto scope = scopes.rbegin(); scope != scopes.rend(); ++scope)
        {
            if ((*scope).find(id) != (*scope).end())
            {
                return (*scope)[id].type;
            }
        }
        return data_type::_INVALID;
    }

    std::string allocateReg(std::ostream &stream)
    {
        for (int i = 0; i < 32; i++)
        {
            if (risc_regs.getReg(i) == 0)
            {
                risc_regs.setReg(i, 1);
                std::string allocated_reg = "x" + std::to_string(i);
                stream << "mv " << allocated_reg << ", zero" << std::endl;
                return allocated_reg;
            }
        }
        return "";  // ERROR
    }

    void deallocateReg(std::string reg)
    {
        int reg_num = std::stoi(reg.substr(1));
        risc_regs.setReg(reg_num, 0);
        std::cout << "Deallocating x" << reg_num << " "
                  << risc_regs.getReg(reg_num) << std::endl;
    }

    std::string allocateFloatReg(std::ostream &stream)
    {
        for (int i = 0; i < 32; i++)
        {
            if (risc_float_regs.getFloatReg(i) == 0)
            {
                risc_float_regs.setFloatReg(i, 1);
                std::string allocated_reg = "f" + std::to_string(i);
                stream << "fsub.s " << allocated_reg << ", " << allocated_reg
                       << ", " << allocated_reg << std::endl;
                return allocated_reg;
            }
        }
        return "";  // ERROR
    }

    void deallocateFloatReg(std::string reg)
    {
        int reg_num = std::stoi(reg.substr(1));
        risc_float_regs.setFloatReg(reg_num, 0);
        std::cout << "Deallocating f" << reg_num << " "
                  << risc_float_regs.getFloatReg(reg_num) << std::endl;
    }

    // For function calls (saving temp registers)
    void saveRegs(std::ostream &stream)
    {
        std::vector<std::string> scopeRegs;
        for (int i = 5; i < 8; i++)
        {
            if (risc_regs.getReg(i) == 1)
            {
                std::string tempReg = "x" + std::to_string(i);
                stream << "sw " << tempReg << ", " << getMemory(INT_MEM)
                       << "(sp)" << std::endl;
                risc_regs.setReg(i, 0);  // TODO: check that this is valid
                scopeRegs.push_back(tempReg);
            }
        }
        for (int i = 28; i < 32; i++)
        {
            if (risc_regs.getReg(i) == 1)
            {
                std::string tempReg = "x" + std::to_string(i);
                stream << "sw " << tempReg << ", " << getMemory(INT_MEM)
                       << "(sp)" << std::endl;
                risc_regs.setReg(i, 0);  // TODO: check that this is valid
                scopeRegs.push_back(tempReg);
            }
        }
        savedRegs.push_back(scopeRegs);
    }

    // TODO: save the float regs as well if time permits.

    void restoreRegs(std::ostream &stream)
    {
        std::vector<std::string> scopeRegs = savedRegs.back();
        int size = scopeRegs.size();
        for (int i = 0; i < size; i++)
        {
            stream << "lw " << scopeRegs.back() << ", " << remaining_mem
                   << "(sp)" << std::endl;
            risc_regs.setReg(std::stoi(scopeRegs.back().substr(1)), 1);
            scopeRegs.pop_back();
            remaining_mem += INT_MEM;
        }
        savedRegs.pop_back();
    }

    void setFunctionReturnType(std::string function_name, data_type return_type)
    {
        function_return_types[function_name] = return_type;
    }

    data_type getFunctionReturnType(std::string function_name)
    {
        if (function_return_types.find(function_name) !=
            function_return_types.end())
        {
            return function_return_types[function_name];
        }
        return data_type::_INVALID;
    }

    void EnterFunction(std::ostream &stream){
        param_stack.push_back(params);
        remaining_mem_stack.push_back(remaining_mem);
        params.clear();              // The param offsets should be pushed into
                                     // functions straight after prolog
        remaining_mem = frame_size;  // Resets offset
        return_branches.push_back(
            makeLabel("function_end"));  // Create a unique label for the
                                         // end of the function
        stream << "addi sp, sp, -" << frame_size << std::endl;
    }

    void CreateScope()
    {
        // Store local variables, parameters and return type
        scopes.push_back(bindings);
        bindings.clear();            // Reset bindings for new scope
    }

    std::string getReturnLabel() { return return_branches.back(); }

    void ExitFunction(std::ostream &stream){
        return_branches.pop_back();
        params = param_stack.back();
        param_stack.pop_back();
        remaining_mem = remaining_mem_stack.back();
        remaining_mem_stack.pop_back();
        stream << "addi sp, sp, " << frame_size << std::endl;
    }

    void ExitScope()
    {
        // Pop the last scope
        bindings = scopes.back();
        scopes.pop_back();
    }

    // Structs
    void InitialiseStruct(
        std::string id,
        std::unordered_map<std::string, data_type> struct_members)
    {
        struct_info[id] = struct_members;
    }

    std::unordered_map<std::string, data_type> getStructMembers(std::string id)
    {
        return struct_info[id];
    }

    void createStructBindings(std::string struct_identifier,
                              std::string instance_identifier)
    {
        // struct x z;
        // create a struct instance of x callled z
        // if x has members y
        // then create bindings for z.y (and any others)
        // so that other classes can access these instance fields.
        std::unordered_map<std::string, data_type> struct_members =
            getStructMembers(struct_identifier);

        std::string binding_id;
        for (auto &member : struct_members)
        {
            binding_id = instance_identifier + "." + member.first;
            createBinding(binding_id, member.second, false);
        }
    }

    void addStringHeader(std::string header_branch, std::string string_literal)
    {
        string_headers[header_branch] = string_literal;
    }

    void printHeader(std::ostream &stream)
    {
        for (auto &header : string_headers)
        {
            stream << header.first << ":" << std::endl;
            stream << "    .string " << header.second << std::endl;
        }
    }

    // Probs won't need
    void AllocateStack(int num_bytes) {}
};
#endif
