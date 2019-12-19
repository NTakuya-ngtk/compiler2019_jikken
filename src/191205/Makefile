YACC = yacc -d

ytab: parser.y
	$(YACC) parser.y

scanner: scanner.l
	lex scanner.l

parser: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -ll -o parser

clean:
	rm parser*.o
	rm scanner*.o
