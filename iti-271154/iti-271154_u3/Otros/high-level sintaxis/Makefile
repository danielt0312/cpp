# put together object files from lexer and parser, and
# link the yacc and lex libraries (in that order, to pick
# main() from yacc's library rather than lex's)

roman : roman.tab.o roman.lex.o
	$(CC) -o $@ roman.tab.o roman.lex.o -ly -ll

# tell make which files yacc will generate
#
# an explanation of the arguments:
# -b roman  -  name the files roman.tab.*
# -d        -  generate a .tab.h file too

roman.tab.h roman.tab.c : roman.y
	$(YACC) -d -b roman $?

# the object file relies on the generated lexer, and
# on the token constants 

roman.lex.o : roman.tab.h roman.lex.c

# can't use the default suffix rule because we're
# changing the name of the output to .lex.c

roman.lex.c : roman.l
	$(LEX) -t $? > $@
