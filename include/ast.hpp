#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

// Misc
#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

// Control Flow
#include "ast/control_flow/ast_jump_statement.hpp"
#include "ast/control_flow/ast_multi_list.hpp"
#include "ast/control_flow/ast_case.hpp"
#include "ast/control_flow/ast_default.hpp"
#include "ast/control_flow/ast_for.hpp"
#include "ast/control_flow/ast_if_statement.hpp"
#include "ast/control_flow/ast_while.hpp"
#include "ast/control_flow/ast_if_else_statement.hpp"
#include "ast/control_flow/ast_switch_statement.hpp"
#include "ast/control_flow/ast_multi_list.hpp"
#include "ast/control_flow/ast_empty_statement.hpp"

// Functions
#include "ast/functions/ast_function_call.hpp"
#include "ast/functions/ast_function_definition.hpp"
#include "ast/functions/ast_parameter_declarator.hpp"
#include "ast/functions/ast_parameter_list.hpp"

// Operators
#include "ast/operators/ast_assignment.hpp"
#include "ast/operators/ast_operators.hpp"
#include "ast/operators/ast_var_assign.hpp"
#include "ast/operators/ast_postfix.hpp"
#include "ast/operators/ast_inequality.hpp"

// Types
#include "ast/types/ast_constant.hpp"
#include "ast/types/ast_type_specifier.hpp"
#include "ast/types/ast_variable.hpp"
#include "ast/types/ast_entity_type.hpp"

// Declarations
#include "ast/ast_declaration.hpp"
#include "ast/ast_direct_declarator.hpp"
#include "ast/ast_identifier.hpp"
#include "ast/ast_init_declarator.hpp"
#include "ast/ast_init_declarator_list.hpp"
#include "ast/ast_array_declarator.hpp"

extern Node *ParseAST(std::string file_name);

#endif
