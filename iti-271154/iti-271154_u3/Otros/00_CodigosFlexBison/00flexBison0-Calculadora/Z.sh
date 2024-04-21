# Recomendacion: Traducir los manuales (Idioma Original : Griego)
# Paso 0: Limpiar el desma
rm *.c *.h *.txt
# Paso 1
flex lexer.l 
# Paso 2
bison -d parser.y 
# Paso 3:
gcc -o parser parser.tab.c lex.yy.c
# Paso 4:
#./parser while.golub
#./parser error.golub 
