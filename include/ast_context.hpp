#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include "ast_data_type.hpp"



// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).

//Stores 
struct function_properties {
    std::vector<std::pair<std::string, data_type>> param; //(change : just storing identifiers)
    data_type return_type; // todo
};

struct variable {};

//Scope : store local var bindings in the memory scope 



class Context
{
    /* TODO decide what goes inside here */
    public:
        std::vector<std::map<std::string, variable>> scopes; //Stores symbol tables
        
        std::map<std::string, function_properties> functions;
        
        std::map<std::string, variable> bindings; //Bindings (Local variables) for current scope


        int frame_size = 128; //Size of stack frame

        void set_function_params(std::string function_name, std::string param_name, data_type param_type){} //TODO: Implement

        void set_local_vars(std::string function_name, std::string var_name, data_type var_type){} //TODO : set bindings 

        

        void CreateScope(std::ostream &stream){
            //Store local variables, parameters and return type
            scopes.push_back(bindings);
            bindings.clear(); //Reset bindings for new scope

            stream << "addi sp, sp, " << frame_size << std::endl;


        }

        //May not need
        void AllocateStack(int num_bytes, std::){
            
        }


};

#endif
