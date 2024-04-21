/* scanner for a toy Pascal-like language */

%{
/* need this for the call to atof() below */
#include <math.h>
#include "tpgram.tab.h"
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%

{DIGIT}+    {
            printf("An integer: %s (%d)\n", yytext, atoi(yytext));
	    return INTCONST;
            }

{DIGIT}+"."{DIGIT}*        {
            printf("A float: %s (%g)\n", yytext, atof(yytext));
	    return REALCONST;
            }

if        {
            printf( "An IF: %s\n", yytext );
	    return IF;
            }

then        {
            printf( "A THEN: %s\n", yytext );
	    return THEN;
            }

begin        {
            printf( "A BEGIN: %s\n", yytext );
	    return BEGIN_T;
            }

end        {
            printf( "An END: %s\n", yytext );
	    return END;
            }

procedure        {
            printf( "A keyword: %s\n", yytext );
	    return PROCEDURE;
            }

function        {
            printf( "A keyword: %s\n", yytext );
	    return FUNCTION;
            }

{ID}        {
		printf( "An identifier: %s\n", yytext );
	    return IDENTIFIER;
	    }

"+"|"-"|"*"|"/"   {
		printf( "An operator: %s\n", yytext );
	    return OPERATOR;
	    }

":="   {
		printf( "An assignment: %s\n", yytext );
	    return ASSIGN;
	    }

";"   {
		printf( "A semi-colon: %s\n", yytext );
	    return SEMICOLON;
	    }

"{"[^}\n]*"}"     {
	    printf( "A comment: %s\n", yytext );
	    /* eat up one-line comments */
	    }

[ \t\n]+          {
		printf( "Whitespace: %s\n", yytext );
		    /* eat up whitespace */
		    }

.            {
	    printf( "Unrecognized character: %s\n", yytext );
	    return UNRECOGNIZED;
	    }

%%
// Pegostar para resarcier el error de undefinded yywrap
int yywrap(){return(1);}
