%{
/* header section.
 * declare terminal and nonterminal symbols
 */
#include <stdio.h>
extern char *yytext;
%}

%token INTCONST
%token REALCONST
%token IF
%token THEN
%token BEGIN_T
%token END
%token PROCEDURE
%token FUNCTION
%token ASSIGN
%token SEMICOLON
%token IDENTIFIER
%token OPERATOR
%token COMMENT
%token WHITESPACE
%token UNRECOGNIZED

%%

program: procedures_or_functions ;

procedures_or_functions:
	procedure procedures_or_functions |
	function procedures_or_functions |
	;

procedure: PROCEDURE IDENTIFIER BEGIN_T statements END ;

function: FUNCTION IDENTIFIER BEGIN_T statements END ;

statements: statement | statements SEMICOLON statement ;

statement: assignment_statement | if_then_statement ;

assignment_statement: IDENTIFIER ASSIGN expr ;

if_then_statement: IF expr THEN statement ;

expr: IDENTIFIER | INTCONST | REALCONST |
	expr OPERATOR expr ;
