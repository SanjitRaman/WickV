#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ast_assignment.hpp"
#include "ast_constant.hpp"
#include "ast_context.hpp"
#include "ast_declaration.hpp"
#include "ast_direct_declarator.hpp"
#include "ast_function_call.hpp"
#include "ast_function_definition.hpp"
#include "ast_identifier.hpp"
#include "ast_if_else_statement.hpp"
#include "ast_if_statement.hpp"
#include "ast_init_declarator.hpp"
#include "ast_init_declarator_list.hpp"
#include "ast_jump_statement.hpp"
#include "ast_multi_list.hpp"
#include "ast_node.hpp"
#include "ast_operators.hpp"
#include "ast_parameter_declarator.hpp"
#include "ast_parameter_list.hpp"
#include "ast_type_specifier.hpp"
#include "ast_var_assign.hpp"
#include "ast_variable.hpp"
#include "ast_while.hpp"
#include "ast_empty_statement.hpp"
#include "ast_inequality.hpp"
#include "ast_for.hpp"
extern Node *ParseAST(std::string file_name);

#endif
