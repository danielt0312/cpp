

# Paso 0: Limpiar el desma
rm *.c *.h 
# Paso 1
flex main.l 
# Paso 2
bison -d main.y 
# Paso 3:
gcc -o parser main.tab.c lex.yy.c -lfl -lm
# Paso 4:
./parser 
# Recibe input como entrada -> Genera output como salida

