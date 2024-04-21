# Paso 0: Limpiar el desma
rm *.cpp *.hpp *.txt
# Paso 1
flex lexer1.l 
# Paso 2
bison -d grammar.y 
# Paso 3:
#gcc -o parser bison.tab.c lex.yy.c -lfl
g++ -o CalculadorV1 Scanner1.cpp Parser1.cpp -lfl
# Paso 4:
./CalculadorV1
