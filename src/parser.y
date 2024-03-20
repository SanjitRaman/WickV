// Adapted from: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html

// TODO: you can either continue adding to this grammar file or
// rename parser_full.y to parser.y once you're happy with
// how this example works.

%code requires{
    #include "ast.hpp"

	extern void update_type_map(std::string identifier, std::string type);
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

%token IDENTIFIER INT_CONSTANT FLOAT_CONSTANT STRING_LITERAL CHAR_LITERAL
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN ASSIGN
%token TYPE_NAME TYPEDEF EXTERN STATIC AUTO REGISTER SIZEOF
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <node> external_declaration function_definition primary_expression postfix_expression
%type <node> unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression
%type <node> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <node> conditional_expression assignment_expression expression constant_expression declaration
%type <node> init_declarator type_specifier struct_specifier struct_declaration specifier_qualifier_list struct_declarator_list
%type <node> struct_declarator enum_specifier enumerator declarator direct_declarator pointer  parameter_declaration declaration_specifiers
%type <node> identifier_list type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement
%type <node> compound_statement expression_statement selection_statement iteration_statement jump_statement storage_class_specifier

%type <nodes> statement_list declaration_list init_declarator_list argument_expression_list translation_unit enumerator_list struct_declaration_list 
%type <parameter_list> parameter_list

%type <string> unary_operator assignment_operator

%type <number_int> INT_CONSTANT
%type <number_float> FLOAT_CONSTANT
%type <string> IDENTIFIER STRING_LITERAL CHAR_LITERAL


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
    | FLOAT_CONSTANT {$$ = new FloatConstant($1);}
	| '(' expression ')' { $$ = $2; } /* TODO: check if this is correct way to parse */
	| STRING_LITERAL { $$ = new StringLiteral(*$1); delete $1; }
	| CHAR_LITERAL { $$ = new CharLiteral(*$1); delete $1; }
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '(' ')' { $$ = new FunctionCall($1); std::cout << "PostfixExpression: " << std::endl;}
	| postfix_expression '(' argument_expression_list ')' { $$ = new FunctionCall($1, $3); }
	| postfix_expression INC_OP {$$ = new PostfixOperator($1, "++"); }
	| postfix_expression DEC_OP {$$ = new PostfixOperator($1, "--"); }
	| postfix_expression '[' expression ']' { $$ = new ArrayIndex($1, $3); }
	| postfix_expression '.' IDENTIFIER { $$ = new MemberAccess($1, *$3); delete $3; }
	/* | postfix_expression PTR_OP IDENTIFIER
	| postfix_expression DEC_OP */
	;

//Should just be a node list
argument_expression_list
	: assignment_expression { $$ = new NodeList($1); }
	| argument_expression_list ',' assignment_expression { $1->PushBack($3); $$ = $1; }
	;

unary_expression
	: postfix_expression { $$ = $1; }
	| unary_operator cast_expression { $$ = new Unary{*$1, $2}; delete $1;} //Should return 
	| SIZEOF unary_expression { $$ = new SizeOf($2); }
	| SIZEOF '(' type_name ')' { $$ = new SizeOf($3); }
	| INC_OP unary_expression {$$ = new PrefixOperator($2, "++"); }
	| DEC_OP unary_expression {$$ = new PrefixOperator($2, "--"); }
	;
	

unary_operator
	: '&' { $$ = new std::string("&"); }
	| '*' { $$ = new std::string("*"); }
	| '+'
	| '-' { $$ = new std::string("-"); }
	| '~'
	| '!'
	;

cast_expression
	: unary_expression { $$ = $1; }
	/* | '(' type_name ')' cast_expression */
	;

multiplicative_expression
	: cast_expression { $$ = $1; }
	| multiplicative_expression '*' cast_expression { $$ = new MultiplyOperator($1, $3);}
	| multiplicative_expression '/' cast_expression { $$ = new DivideOperator($1, $3); }
	| multiplicative_expression '%' cast_expression { $$ = new ModulusOperator($1, $3); }
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression {
		$$ = new AddOperator($1, $3);
	}
	| additive_expression '-' multiplicative_expression {
		$$ = new SubtractOperator($1, $3);
	}
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression { $$ = new LeftShift($1, $3); }
	| shift_expression RIGHT_OP additive_expression { $$ = new RightShift($1, $3); std::cout << "ShiftExpression: RIGHT_OP" << std::endl;}
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '>' shift_expression { $$ = new GreaterThan($1, $3); }
	| relational_expression '<' shift_expression { $$ = new LessThan($1, $3); }
	| relational_expression LE_OP shift_expression { $$ = new LessThanEqual($1, $3); }
	| relational_expression GE_OP shift_expression { $$ = new GreaterThanEqual($1, $3); }
	;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression EQ_OP relational_expression { $$ = new Equality($1, $3); }
	| equality_expression NE_OP relational_expression { $$ = new NotEqual($1, $3); }
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression { $$ = new BitwiseAndOperator($1, $3); }
	;

exclusive_or_expression
	: and_expression { $$ = $1; }
	| exclusive_or_expression '^' and_expression { $$ = new BitwiseXorOperator($1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
    | inclusive_or_expression '|' exclusive_or_expression { $$ = new BitwiseOrOperator($1, $3); }

	;

logical_and_expression
	: inclusive_or_expression { $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression { $$ = new LogicalAndOperator($1, $3); }
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression { $$ = new LogicalOrOperator($1, $3);}
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { $$ = new Ternary($1, $3, $5); }

	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression assignment_operator assignment_expression {$$ = new Assignment($1, *$2, $3); delete $2;} //Do I have to delete $2? */
	;

//TODO: Implement the rest of the assignment operators
assignment_operator
	: '=' { $$ = new std::string("="); }
	| MUL_ASSIGN { $$ = new std::string("*="); }
	| DIV_ASSIGN {$$ = new std::string("/=");}
	| MOD_ASSIGN { $$ = new std::string("%=");}
	| ADD_ASSIGN { $$ = new std::string("+=");}
	| SUB_ASSIGN { $$ = new std::string("-=");}
	| LEFT_ASSIGN { $$ = new std::string("<<=");}
	| RIGHT_ASSIGN { $$ = new std::string(">>=");}
	| AND_ASSIGN { $$ = new std::string("&=");}
	| XOR_ASSIGN { $$ = new std::string("^=");}
	| OR_ASSIGN { $$ = new std::string("|=");}
	;
//TODO: What I am supposed to do here
expression
	: assignment_expression { $$ = $1; }
	/* | expression ',' assignment_expression */
	;

constant_expression
	: conditional_expression { $$ = $1; }
	;

declaration
	: declaration_specifiers ';' { $$ = $1; }// Unsure what to do here
	| declaration_specifiers init_declarator_list ';' 
	{if ($1->getEntity() == entity_type::TYPEDEF_DEC){ 
			update_type_map($2->getNodes()[0]->getId(), $1->getId());
			std::cout << "DeclarationSpecifier: typedef" << std::endl;
		}
		else{
			$$ = new Declaration($1, $2);
		} 
	} 
	;

declaration_specifiers
	   : type_specifier { $$ = $1; std::cout << "DeclarationSpecifier: " << std::endl; }
	   | storage_class_specifier declaration_specifiers { $$ = new TypedefDeclaration($1, $2); std::cout << "DeclarationSpecifier: " << std::endl; }
	   /*| storage_class_specifier declaration_specifiers { if (*$1 == "typedef") { update_type_map($2->getNodes()[1]->getId(), $2->getNodes()[0]->getId()) } delete $1; } */
	   /* | type_specifier declaration_specifiers  { $$ = $2; $2->PushBack($1); } */
	;
	/* : storage_class_specifier */

init_declarator_list
	: init_declarator { $$ = new InitDeclaratorList($1); } //Node (Declaration)
	| init_declarator_list ',' init_declarator {$$ = $1; $1->PushBack($3);} //NodeList (DeclarationList with vars and Declaration)
	;

init_declarator
	: declarator {std::cout << "Could be an error with InitDeclarator" ;$$ = new InitDeclarator($1); std::cout << "It's going to InitDeclarator : declarator" << std::endl; }//create a declaration (just var, or function def might be fine) here with the declarator variable
	| declarator '=' initializer {$$ = new VarAssign($1, $3); } // () Create a declaration here with the declarator variable and the initializer - type is set in Declaration
	;

storage_class_specifier
	: TYPEDEF {$$ = new Typedef("typedef"); }
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;


//Create bindings in Declaration for each init_declarator
// Assign the value of the initializer to the declarator in VarAssign->EmitRISC()
//Check all types are fully supported
type_specifier
	: INT {
		$$ = new TypeSpecifier("int"); std::cout << "TypeSpecifier: " << std::endl;	
	}
	| enum_specifier { $$ = $1; } //This should be fine
	| FLOAT { $$ = new TypeSpecifier("float"); std::cout << "TypeSpecifier: float" << std::endl; }
	| DOUBLE { $$ = new TypeSpecifier("double"); std::cout << "TypeSpecifier: double" << std::endl; }
	| struct_specifier { $$ = $1; }
	| CHAR { $$ = new TypeSpecifier("char"); std::cout << "TypeSpecifier: char" << std::endl; }
	| UNSIGNED { $$ = new TypeSpecifier("unsigned"); std::cout << "TypeSpecifier: unsigned" << std::endl; }
	| VOID { $$ = new TypeSpecifier("void"); std::cout << "TypeSpecifier: void" << std::endl; }
	;
	/* | TYPE_NAME {  } */
	/*
	| SHORT
	| LONG
	| SIGNED
	
	;
*/
struct_specifier
	: STRUCT IDENTIFIER '{' struct_declaration_list '}'  { $$ = new StructSpecifier(*$2, $4); delete $2; }
	| STRUCT IDENTIFIER { $$ = new StructDec(*$2); delete $2; }
	/* | STRUCT '{' struct_declaration_list '}' */
	

struct_declaration_list
	: struct_declaration { $$ = new NodeList($1); }
	| struct_declaration_list struct_declaration { $1->PushBack($2); $$ = $1; }

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' { $$ = new StructMember($1, $2); }
//Name of global struct -> Name of the member variable and the type of the member variable
specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier { $$ = $1; } 

struct_declarator_list
	: struct_declarator { $$ = new StructDeclaratorList($1); } //TODO: Change to a custom NodeList
	| struct_declarator_list ',' struct_declarator 


struct_declarator
	: declarator { $$ = $1;}
	/* | ':' constant_expression
	| declarator ':' constant_expression */
	;


enum_specifier
	: ENUM '{' enumerator_list '}' { $$ = new EnumSpecifier("", $3); }
	| ENUM IDENTIFIER '{' enumerator_list '}' { $$ = new EnumSpecifier(*$2, $4); delete $2; }
	| ENUM IDENTIFIER { $$ = new EnumSpecifier(*$2, nullptr); delete $2; }
	;

enumerator_list
	: enumerator { $$ = new NodeList($1); }
	| enumerator_list ',' enumerator { $1->PushBack($3); $$ = $1; }
	;

enumerator
	: IDENTIFIER { $$ = new Enumerator(*$1, nullptr); delete $1; std::cout << "goes to enumerator:identifier" << std::endl;}
	| IDENTIFIER '=' constant_expression { $$ = new Enumerator(*$1, $3); delete $1; std::cout << "goes to enumerator:identifier = constant_expression" << std::endl;} //2 constructors for Enumerator
	;


declarator
	: direct_declarator { $$ = $1; std::cout << "It's going to Declarator : direct_declarator" << std::endl;}
	| pointer direct_declarator { $$ = new PointerDeclarator($1, $2); std::cout << "It's going to Declarator : pointer direct_declarator" << std::endl;}
	;
//Only use DirectDeclarator for function defs
direct_declarator
    : IDENTIFIER {
        $$ = new Variable(*$1); //CHANGED FROM Identifier to Variable
        delete $1;
    }
	| direct_declarator '[' constant_expression ']' { $$ = new ArrayDeclarator($1, $3); }
    /* | '(' declarator ')'
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

pointer
	: '*' { $$ = new Pointer(); }
	| '*' pointer
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

type_name
	: specifier_qualifier_list { $$ = $1; }
	/* | specifier_qualifier_list abstract_declarator */
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
	| compound_statement {$$ = $1; }
	| selection_statement {$$ = $1; }
	| iteration_statement {$$ = $1; }
	| labeled_statement {$$ = $1;}
  	;

labeled_statement
	: CASE constant_expression ':' statement { $$ = new CaseStatement($2, $4); }
	/* : IDENTIFIER ':' statement */
	| DEFAULT ':' statement { $$ = new DefaultStatement($3); }
	;

compound_statement
	: '{' '}' {
		// TODO: correct this
		$$ = new EmptyStatement();
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
	: ';' { $$ = new Semicolon();}
	| expression ';' { $$ = $1; }
	;

selection_statement
	: IF '(' expression ')' statement { $$ = new IfStatement($3, $5); }
	| IF '(' expression ')' statement ELSE statement { $$ = new IfElseStatement($3, $5, $7); }
	| SWITCH '(' expression ')' statement { $$ = new SwitchStatement($3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement { $$ = new WhileStatement($3, $5); }
	| FOR '(' expression_statement expression_statement expression ')' statement { $$ = new ForStatement($3, $4, $5, $7); std::cout << "IterationStatement: " << std::endl;}
	/* | DO statement WHILE '(' expression ')' ';' */
	| FOR '(' expression_statement expression_statement ')' statement { $$ = new ForStatement($3, $4, $6); }
	;

jump_statement
	: CONTINUE ';' {
		$$ = new Continue();
	}
	| BREAK ';' {
		$$ = new Break();
	}
	| RETURN ';' {
		$$ = new ReturnStatement(nullptr); //TODO : Create 2 constructors if time
	}
	| RETURN expression ';' {
		$$ = new ReturnStatement($2);
	}
	/* |  GOTO IDENTIFIER ';' */
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
