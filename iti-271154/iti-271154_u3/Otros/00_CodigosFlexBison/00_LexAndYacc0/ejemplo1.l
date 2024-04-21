%{
int lineNum = 0;

%}
%%
[a-zA-Z] {printf ("Letra");}
[a-zA-Z]+ {printf ("Palabra");}
[0-9] {printf ("Digito");}
[0-9]+ {printf ("Numero");}
"(" { printf("("); }
")" { printf(")"); }
"+" { printf("+"); }
"*" { printf("*"); }
\n { lineNum++; }

%%

int yywrap() {
return 1;
}

int main () {yylex();}
