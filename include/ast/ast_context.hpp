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
    std::vector<std::string> switch_labels;
    std::vector<std::string> default_labels;
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
    entity_type type;
};

struct param
{
    std::string offset;
    entity_type type;
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

class Context
{
   protected:
    reg_file risc_regs;
    int makeLabelUnq = 0;
    /* TODO decide what goes inside here */
   public:
    std::vector<std::unordered_map<std::string, variable>>
        scopes;                                     // Stores symbol tables
    std::unordered_map<std::string, param> params;  // Clear params in exit
                                                    // scope
    std::unordered_map<std::string, function_properties> functions;
    std::vector<std::string> return_branches;
    std::unordered_map<std::string, variable>
        bindings;  // Bindings (Local variables) for current scope
    switch_properties switch_info;
    std::string caseLabel = "";
    std::vector<loop_labels> loop_info;

    bool fetchArrayIndex = false;
    std::string ArrayIndexReg = "";



    int frame_size = 128;  // Size of stack frame
    int remaining_mem;     // Offset

    std::string makeLabel(std::string base)
    {
        return "_" + base + "_" + std::to_string(makeLabelUnq++);
    }
    //For loops
    void createLoop(std::string start, std::string end, std::string update)
    {
        loop_labels new_loop;
        new_loop.startLabel = start;
        new_loop.endLabel = end;
        new_loop.updateLabel = update;
        loop_info.push_back(new_loop);
    }

    //While loops
    void createLoop(std::string start, std::string end)
    {
        loop_labels new_loop;
        new_loop.startLabel = start;
        new_loop.updateLabel = "";
        new_loop.endLabel = end;
        loop_info.push_back(new_loop);
    }
    std::string getLoopStart()
    {
        return loop_info.back().startLabel;
    }
    std::string getLoopEnd()
    {
        return loop_info.back().endLabel;
    }

    std::string getLoopUpdate()
    {
        return loop_info.back().updateLabel;
    }

    void exitLoop()
    {
        loop_info.pop_back();
    }


    void InitialiseSwitch()
    {
        std::string switch_label = makeLabel("end_switch");
        switch_info.switch_labels.push_back(switch_label);
        loop_labels new_switch;
        new_switch.startLabel = "";
        new_switch.updateLabel = "";
        new_switch.endLabel = switch_label;
        loop_info.push_back(new_switch);
    }
    void setCaseLabel()
    {
        std::string case_label = makeLabel("case_statement");
        caseLabel = case_label;
    }

    std::string getCaseLabel()
    {
        return caseLabel;
    }

    std::string getSwitchLabel(){
        return switch_info.switch_labels.back();
    }

    void ExitSwitch(bool is_default = false)
    {
        if (is_default)
        {
            switch_info.default_labels.pop_back();
        }
        switch_info.switch_labels.pop_back();
        loop_info.pop_back();
    }

    void setDefaultLabel()
    {
        std::string default_statement = makeLabel("default");
        switch_info.default_labels.push_back(default_statement);
    }

    std::string getDefaultLabel()
    {
        if (switch_info.default_labels.empty())
        {
            return "";
        }
        return switch_info.default_labels.back();
    }

    void set_function_params(std::string function_name,
                             function_properties function_info)
    {
    }  // TODO: Implement to update params (call in function_definition after
       // prolog)

    void update_params(std::string param_name, entity_type param_type,
                       std::string param_offset)
    {
        param new_param;
        new_param.type = param_type;
        new_param.offset = param_offset;
        params[param_name] = new_param;

    }  // TODO: call to update params in parameter_list DONE

    void set_local_vars(std::string function_name, std::string var_name,
                        entity_type var_type)
    {
    }  // TODO : set bindings (may not need to link to function)

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


    void addArray(std::string id, int array_size)
    {
        std::string offset;
        //Binding created in InitDeclarator/Declaration
        if (bindings[id].type == entity_type::INTEGER)
        {
            for (int i = 0; i < array_size - 1; i++)
            {
                offset = getMemory(INT_MEM);
            }
        }
    }
    void setFetchIndexReg(bool shouldFetch){
        fetchArrayIndex = shouldFetch;
        //If shouldFetch is true, then fetch the array index
        //If shouldFetch is false, then don't fetch the array index
    }

    bool getFetchIndexReg(){
        return fetchArrayIndex;
    }

    void setIndexReg(std::string index_reg){
        ArrayIndexReg = index_reg;
    }

    std::string getIndexReg(){
        return ArrayIndexReg;
        //TODO: Maybe reset ArrayIndexReg to "" after use of this method???
    }

    // Change entity_type to data_type
    void createBinding(std::string id, entity_type type)
    {
        std::string offset = getMemory(INT_MEM);
        variable newVar;
        newVar.offset = offset;
        newVar.type = type;
        bindings[id] = newVar;
    }

    std::string getOffset(std::string id)
    {
        if (bindings.find(id) != bindings.end())
        {
            return bindings[id].offset;
        }
        return "ERROR : getOffset";
    }

    entity_type getBindingType(std::string id)
    {
        if (bindings.find(id) != bindings.end())
        {
            return bindings[id].type;
        }
        return entity_type::INVALID;
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

        void CreateScope(std::ostream & stream)
        {
            // Store local variables, parameters and return type
            scopes.push_back(bindings);
            bindings.clear();            // Reset bindings for new scope
            remaining_mem = frame_size;  // Resets offset
            return_branches.push_back(
                makeLabel("function_end"));  // Create a unique label for the
                                             // end of the function
            stream << "addi sp, sp, -" << frame_size << std::endl;
        }
        std::string getReturnLabel() { return return_branches.back(); }

        void ExitScope(std::ostream & stream)
        {
            // Pop the last scope
            return_branches.pop_back();
            bindings = scopes.back();
            scopes.pop_back();
            params.clear();  // The param offsets should be pushed into
                             // functions straight after prolog
            stream << "addi sp, sp, " << frame_size << std::endl;
        }

        // Probs won't need
        void AllocateStack(int num_bytes) {}
    };
#endif
