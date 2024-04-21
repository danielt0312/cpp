#
# Makefile for tiny pascal compiler example.
#

# the tinypascal executable tp is produced by linking 3 .o files, + libraries
tp: lex.yy.o tpgram.tab.o tp.o
	gcc -o tp lex.yy.o tpgram.tab.o tp.o -lfl

#
# .o files are compiled from .c files via "gcc -c". Could add -g for debugging.
# If a .c file includes a .h file, the .o "depends" on that .h file too.
#
lex.yy.o: lex.yy.c tpgram.tab.h
	gcc -c lex.yy.c

tpgram.tab.o: tpgram.tab.c
	gcc -c tpgram.tab.c

tp.o: tp.c
	gcc -c tp.c

#
# In the case of Flex and Bison, the .c files are generated from .l and .y
#
lex.yy.c: tinypas.l
	flex tinypas.l

tpgram.tab.c: tpgram.y
	bison -d tpgram.y

tpgram.tab.h: tpgram.tab.c
