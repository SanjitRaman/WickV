#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

// Misc
#include "ast/ast_node.hpp"
#include "ast/ast_context.hpp"

// Control Flow
#include "ast/control_flow/ast_multi_list.hpp"
#include "ast/control_flow/ast_jump_statement.hpp"

// Functions
#include "ast/functions/ast_function_definition.hpp"
#include "ast/functions/ast_parameter_declarator.hpp"
#include "ast/functions/ast_parameter_list.hpp"
#include "ast/functions/ast_function_call.hpp"

// Operators
#include "ast/operators/ast_operators.hpp"
#include "ast/operators/ast_var_assign.hpp"
#include "ast/operators/ast_assignment.hpp"

// Types
#include "ast/types/ast_type_specifier.hpp"
#include "ast/types/ast_constant.hpp"
#include "ast/types/ast_variable.hpp"

// Declarations
#include "ast/ast_declaration.hpp"
#include "ast/ast_direct_declarator.hpp"
#include "ast/ast_init_declarator.hpp"
#include "ast/ast_init_declarator_list.hpp"
#include "ast/ast_identifier.hpp"

extern Node *ParseAST(std::string file_name);

#endif
