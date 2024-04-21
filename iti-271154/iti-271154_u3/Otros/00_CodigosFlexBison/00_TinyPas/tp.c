#include <stdio.h>
extern FILE *yyin;
extern int yyparse();

main( argc, argv )
int argc;
char **argv;
    {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;
    if (yyin == NULL) {
       printf("couldn't open...\n");
       }
    else if (yyin == stdin) {
       printf("trying from stdin...\n");
       }
    yyparse();
    }

extern char *yytext;

int yyerror(char *s)
{
   fprintf(stderr, " %s in token %s!!!\n", s, yytext);
   return 0;
}

