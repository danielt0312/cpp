# Paso 0: Limpiar el desma
rm *.c *.h *.txt
# Paso 1
flex basic.l 
# Paso 2
bison -d basic.y 
# Paso 3:
#gcc -o parser bison.tab.c lex.yy.c -lfl
g++ -o basic basic.tab.c lex.yy.c -lfl
# Paso 4:
./basic
