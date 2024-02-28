#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>
#include "ast_data_type.hpp"



// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).

//Stores 


struct variable {};


struct param {
    std::string param_name;
    std::string offset;
    data_type type;
};
//Scope : store local var bindings in the memory scope 



class Context
{
    /* TODO decide what goes inside here */
    public:
        std::vector<std::unordered_map<std::string, variable>> scopes; //Stores symbol tables
        std::unordered_map<std::string, param> params; //Clear params in exit scope
        std::unordered_map<std::string, function_properties> functions;
        
        std::unordered_map<std::string, variable> bindings; //Bindings (Local variables) for current scope


        int frame_size = 128; //Size of stack frame
        int remaining_mem; //Offset 
        

        void set_function_params(std::string function_name, function_properties function_info){} //TODO: Implement to update params (call in function_definition after prolog)


        void update_params(std::string param_name, data_type param_type, std::string param_offset){
            param new_param;
            new_param.param_name = param_name;
            new_param.type = param_type;
            new_param.offset = param_offset;


        } //TODO: call to update params in parameter_list

        void set_local_vars(std::string function_name, std::string var_name, data_type var_type){} //TODO : set bindings 

        std::string getMemory(int mem_size){
            if (remaining_mem == 0){
                return ""; //ERROR            
            }
            else{
                remaining_mem -= mem_size;
                return std::to_string(remaining_mem);
            }
        }
        

        void CreateScope(std::ostream &stream){
            //Store local variables, parameters and return type
            scopes.push_back(bindings);
            bindings.clear(); //Reset bindings for new scope
            remaining_mem = frame_size; //Resets offset 
            stream << "addi sp, sp, -" << frame_size << std::endl;


        }


        //Probs won't need
        void AllocateStack(int num_bytes){}


};

#endif
