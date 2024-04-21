/* catcot.l */

%{
#include <stdio.h>
%}

%%

cot { printf("portable bed"); }
cat { printf("thankless pet"); }
cats { printf("anti-herd"); }

%%
int yywrap() { /* need this to avoid link problem */
return 1;
}
