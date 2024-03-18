#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

// Misc
#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"

// Control Flow
#include "ast/control_flow/ast_break.hpp"
#include "ast/control_flow/ast_case.hpp"
#include "ast/control_flow/ast_continue.hpp"
#include "ast/control_flow/ast_default.hpp"
#include "ast/control_flow/ast_empty_statement.hpp"
#include "ast/control_flow/ast_for.hpp"
#include "ast/control_flow/ast_if_else_statement.hpp"
#include "ast/control_flow/ast_if_statement.hpp"
#include "ast/control_flow/ast_jump_statement.hpp"
#include "ast/control_flow/ast_multi_list.hpp"
#include "ast/control_flow/ast_semicolon.hpp"
#include "ast/control_flow/ast_switch_statement.hpp"
#include "ast/control_flow/ast_while.hpp"

// Functions
#include "ast/functions/ast_function_call.hpp"
#include "ast/functions/ast_function_definition.hpp"
#include "ast/functions/ast_parameter_declarator.hpp"
#include "ast/functions/ast_parameter_list.hpp"

// Structs
#include "ast/structs/ast_member_access.hpp"
#include "ast/structs/ast_struct_dec.hpp"
#include "ast/structs/ast_struct_declarator_list.hpp"
#include "ast/structs/ast_struct_member.hpp"
#include "ast/structs/ast_struct_specifier.hpp"

// Operators
#include "ast/operators/ast_assignment.hpp"
#include "ast/operators/ast_equality.hpp"
#include "ast/operators/ast_inequality.hpp"
#include "ast/operators/ast_operators.hpp"
#include "ast/operators/ast_pointer.hpp"
#include "ast/operators/ast_postfix.hpp"
#include "ast/operators/ast_shift.hpp"
#include "ast/operators/ast_ternary.hpp"
#include "ast/operators/ast_unary.hpp"
#include "ast/operators/ast_var_assign.hpp"

// Types
#include "ast/types/ast_constants.hpp"
#include "ast/types/ast_entity_type.hpp"
#include "ast/types/ast_enum_specifier.hpp"
#include "ast/types/ast_enumerator.hpp"
#include "ast/types/ast_sizeof.hpp"
#include "ast/types/ast_string_literal.hpp"
#include "ast/types/ast_char_literal.hpp"
#include "ast/types/ast_type_specifier.hpp"
#include "ast/types/ast_variable.hpp"

// Declarations
#include "ast/ast_declaration.hpp"
#include "ast/ast_direct_declarator.hpp"
#include "ast/ast_identifier.hpp"
#include "ast/ast_init_declarator.hpp"
#include "ast/ast_init_declarator_list.hpp"
#include "ast/ast_pointer_declarator.hpp"

// Arrays
#include "ast/ast_array_declarator.hpp"
#include "ast/ast_array_index.hpp"

extern Node *ParseAST(std::string file_name);

#endif
