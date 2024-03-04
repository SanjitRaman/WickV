// Adapted from: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html

// TODO: you can either continue adding to this grammar file or
// rename parser_full.y to parser.y once you're happy with
// how this example works.

%code requires{
    #include "ast.hpp"

    extern Node *g_root;
    extern FILE *yyin;
    int yylex(void);
    void yyerror(const char *);
}

// Represents the value associated with any kind of AST node.
%union{
  Node         *node;
  NodeList     *nodes;
  ParameterList *parameter_list;
  // DeclarationList *declaration_list;
  int          number_int;
  double       number_float;
  std::string  *string;
  yytokentype  token;
}

%token IDENTIFIER INT_CONSTANT FLOAT_CONSTANT STRING_LITERAL
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN ASSIGN
%token TYPE_NAME TYPEDEF EXTERN STATIC AUTO REGISTER SIZEOF
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <node> external_declaration function_definition primary_expression postfix_expression
%type <node> unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression
%type <node> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <node> conditional_expression assignment_expression expression constant_expression declaration declaration_specifiers
%type <node> init_declarator type_specifier struct_specifier struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list
%type <node> struct_declarator enum_specifier enumerator_list enumerator declarator direct_declarator pointer  parameter_declaration
%type <node> identifier_list type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement
%type <node> compound_statement expression_statement selection_statement iteration_statement jump_statement

%type <nodes> statement_list declaration_list init_declarator_list argument_expression_list translation_unit
%type <parameter_list> parameter_list

%type <string> unary_operator assignment_operator storage_class_specifier

%type <number_int> INT_CONSTANT STRING_LITERAL
%type <number_float> FLOAT_CONSTANT
%type <string> IDENTIFIER


%start ROOT
%%

ROOT
    : translation_unit { g_root = $1; }

translation_unit
	: external_declaration { $$ = new NodeList($1); }
	| translation_unit external_declaration { $1->PushBack($2); $$ = $1;}
	;

external_declaration
	: function_definition { $$ = $1; }
	| declaration { $$ = $1; }
	;

function_definition
	: declaration_specifiers declarator compound_statement {
		$$ = new FunctionDefinition($1, $2, $3);
		std::cout << "FunctionDefinition: " << std::endl;
	}
	;


primary_expression
	: IDENTIFIER {
		$$ = new Variable(*$1); //Variable?
		delete $1;
	}
	| INT_CONSTANT {
		$$ = new IntConstant($1);
	}
    /* | FLOAT_CONSTANT
	| STRING_LITERAL
	| '(' expression ')' */
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '(' ')' { $$ = new FunctionCall($1); std::cout << "PostfixExpression: " << std::endl;}
	| postfix_expression '(' argument_expression_list ')' { $$ = new FunctionCall($1, $3); }
	/* | postfix_expression '[' expression ']'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP */
	;

//Should just be a node list
argument_expression_list
	: assignment_expression { $$ = new NodeList($1); }
	| argument_expression_list ',' assignment_expression { $1->PushBack($3); $$ = $1; }
	;

unary_expression
	: postfix_expression { $$ = $1; }
	/* | INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')' */
	;

cast_expression
	: unary_expression { $$ = $1; }
	/* | '(' type_name ')' cast_expression */
	;

multiplicative_expression
	: cast_expression { $$ = $1; }
	/* | multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression */
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression {
		$$ = new AddOperator($1, $3);
	}
	/* | additive_expression '-' multiplicative_expression */
	;

shift_expression
	: additive_expression { $$ = $1; }
	/* | shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression */
	;

relational_expression
	: shift_expression { $$ = $1; }
	/* | relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression */
	;

equality_expression
	: relational_expression { $$ = $1; }
	/* | equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression */
	;

and_expression
	: equality_expression { $$ = $1; }
	/* 	| and_expression '&' equality_expression */
	;

exclusive_or_expression
	: and_expression { $$ = $1; }
	/* 	| exclusive_or_expression '^' and_expression */
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
    /* | inclusive_or_expression '|' exclusive_or_expression */

	;

logical_and_expression
	: inclusive_or_expression { $$ = $1; }
	/* 	| logical_and_expression AND_OP inclusive_or_expression */
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	/* 	| logical_or_expression OR_OP logical_and_expression */
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	/*| logical_or_expression '?' expression ':' conditional_expression */

	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression assignment_operator assignment_expression {$$ = new Assignment($1, *$2, $3); delete $2;} //Do I have to delete $2? */
	;

assignment_operator
	: '=' { $$ = new std::string("="); }
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression { $$ = $1; }
	/* | expression ',' assignment_expression */
	;

declaration
	: declaration_specifiers ';' // Unsure what to do here
	| declaration_specifiers init_declarator_list ';' { $$ = new Declaration($1, $2); } //(Set type of declaration here) //use a for loop here to set the type of each declaration (in declaration, set the type of each init_declarator)
	;

declaration_specifiers
	   : type_specifier { $$ = $1; std::cout << "DeclarationSpecifier: " << std::endl; }
	;
	/* : storage_class_specifier */
	/* | storage_class_specifier declaration_specifiers */
	
	/* | type_specifier declaration_specifiers */

init_declarator_list
	: init_declarator { $$ = new InitDeclaratorList($1); } //Node (Declaration)
	| init_declarator_list ',' init_declarator {$$ = $1; $1->PushBack($3);} //NodeList (DeclarationList with vars and Declaration)
	;

init_declarator
	: declarator {std::cout << "Could be an error with InitDeclarator" ;$$ = new InitDeclarator($1); std::cout << "It's going to InitDeclarator : declarator" << std::endl; }//create a declaration (just var, or function def might be fine) here with the declarator variable
	| declarator '=' initializer {$$ = new VarAssign($1, $3); } // () Create a declaration here with the declarator variable and the initializer - type is set in Declaration
	;

//Create bindings in Declaration for each init_declarator
// Assign the value of the initializer to the declarator in VarAssign->EmitRISC()

type_specifier
	: INT {
		$$ = new TypeSpecifier("int"); std::cout << "TypeSpecifier: " << std::endl;	
	}
	;

declarator
	: direct_declarator { $$ = $1; std::cout << "It's going to Declarator : direct_declarator" << std::endl;}
	/* | pointer direct_declarator */
	;
//Only use DirectDeclarator for function defs
direct_declarator
    : IDENTIFIER {
        $$ = new Variable(*$1); //CHANGED FROM Identifier to Variable
        delete $1;
    }
    /* | '(' declarator ')'
    | direct_declarator '[' constant_expression ']'
    | direct_declarator '[' ']' */
    | direct_declarator '(' parameter_list ')' {
		$$ = new DirectDeclarator($1, $3);
	}
    /* | direct_declarator '(' identifier_list ')' */
    | direct_declarator '(' ')' {
        $$ = new DirectDeclarator($1);
		std::cout << "DirectDeclarator: " << std::endl;
    }
    ;

parameter_list
	: parameter_declaration {$$ = new ParameterList($1);}
	| parameter_list ',' parameter_declaration {$$ = $1; $1->PushBack($3);}
	;

parameter_declaration
	: declaration_specifiers declarator {$$ = new ParameterDeclarator($1, $2); std::cout << "ParameterDeclaration: " << std::endl;}
	/* | declaration_specifiers abstract_declarator
	| declaration_specifiers */
	;

initializer
	: assignment_expression { $$ = $1; std::cout << "Initializer: " << std::endl;}
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer 
	| initializer_list ',' initializer
	;


statement
	: jump_statement { $$ = $1; }
	| expression_statement { $$ = $1; }
	| selection_statement { $$ = $1; }
	/* | labeled_statement
	| compound_statement
	
	| iteration_statement
	; */

compound_statement
	: '{' '}' {
		// TODO: correct this
		$$ = nullptr;
	}
	| '{' statement_list '}' { $$ = $2; }
	| '{' declaration_list '}' { $$ = $2; }
	| '{' declaration_list statement_list '}' { $$ = new MultiList($2, $3); } //May need to change
	;
declaration_list
	: declaration { $$ = new NodeList($1); }
	| declaration_list declaration {$1->PushBack($2); $$ = $1;}//Create declaration list here
	;
statement_list
	: statement { $$ = new NodeList($1); }
	| statement_list statement { $1->PushBack($2); $$=$1; }
	;

expression_statement
	: ';'
	| expression ';' { $$ = $1; }
	;
selection_statement
	: IF '(' expression ')' statement { $$ = new IfStatement($3, $5); }
	| IF '(' expression ')' statement ELSE statement { $$ = new IfElseStatement($3, $5, $7); }
	| SWITCH '(' expression ')' statement
	;

jump_statement
	: RETURN ';' {
		$$ = new ReturnStatement(nullptr);
	}
	| RETURN expression ';' {
		$$ = new ReturnStatement($2);
	}
	;


%%

Node *g_root;

Node *ParseAST(std::string file_name)
{
  yyin = fopen(file_name.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << file_name << std::endl;
    exit(1);
  }
  g_root = nullptr;
  yyparse();
  return g_root;
}
