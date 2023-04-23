CC = gcc
CFLAGS = -Wall -I src -Werror
CPPFLAGS = -MMD -c 

all: bin/app.out

bin/app.out: src/app/geometry.c obj/lib.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/lib.a: obj/input_checker.o obj/lexer.o obj/parser.o
	ar rcs $@ $^

obj/input_checker.o: src/lib/input_checker.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/lexer.o: src/lib/lexer.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/parser.o: src/lib/parser.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

clean:
	rm obj/*.*
	rm bin/*.out
	test: test/main.c
test: test/main.c

test/main.c: obj/test/*.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm