/* roman-lex.l */

/* the %{ ... %} enclose C blocks that are copied
   into the generated code */

%{
#include <stdio.h>
#include <stdlib.h>

/* globals are visible to user actions amd main() */

int total;
%}

%%

 /*<- notice the whitespace before this comment, which
      is necessary for comments in the rules section */

 /* the basics */

I  { total +=    1; }
V  { total +=    5; }
X  { total +=   10; }
L  { total +=   50; }
C  { total +=  100; }
D  { total +=  500; }
M  { total += 1000; }

 /* special cases match with preference
    because they are longer strings */

IV { total +=    4; }
IX { total +=    9; }
XL { total +=   40; }
XC { total +=   90; }
CD { total +=  400; }
CM { total +=  900; }

 /* ignore final newline */

\n ;

 /* but die on anything else */

.  {
	fprintf(stderr, "unexpected: %s\n", yytext);
	exit(EXIT_FAILURE);
}

%%

/* provide our own main() rather than the implementation
   from lex's library linked with -ll */

int main(void)
{
	/* only have to call yylex() once, since our
	   actions don't return */
	yylex();

	fprintf(yyout, "%d\n", total);
	return EXIT_SUCCESS;
}
