YACC = yacc -d

parser: y.tab.c lex.yy.c symbol.c
	gcc y.tab.c lex.yy.c -ll -o parser -g

y.tab.c: parser.y
	$(YACC) parser.y

lex.yy.c: scanner.l y.tab.h
	lex scanner.l

y.tab.h: parser.y
	$(YACC) parser.y

clean:
	rm y.tab.*
	rm lex.yy.c
	rm parser
	rm *~

