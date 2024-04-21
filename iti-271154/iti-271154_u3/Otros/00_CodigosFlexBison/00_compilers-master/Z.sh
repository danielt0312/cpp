# Recomendacion: Traducir los manuales (Idioma Original : Griego)
# Paso 0: Limpiar el desma
rm *.c *.h *.txt
# Paso 1
flex flex.l 
# Paso 2
bison -d bison.y 
# Paso 3:
gcc -o parser bison.tab.c lex.yy.c -lfl
# Paso 4:
#./parser while.golub
./parser error.golub 
