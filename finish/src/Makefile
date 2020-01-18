YACC = yacc -d

parser : lex.yy.c y.tab.c table.c control.c output.c
	cc lex.yy.c y.tab.c table.c control.c output.c -ll -o parser

lex.yy.c : scanner.l
	lex scanner.l

y.tab.c : parser.y
	$(YACC) parser.y

clean :
	rm -f y.tab.* lex.yy.c parser