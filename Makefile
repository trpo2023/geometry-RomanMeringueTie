CC = gcc
CFLAGS = -Wall -I src -I thirdparty -Werror -MMD
CPPFLAGS = -c 

all: bin/app.out

bin/app.out: src/app/geometry.c obj/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/lib/lib.a: obj/lib/input_checker.o obj/lib/lexer.o obj/lib/parser.o
	ar rcs $@ $^

obj/lib/input_checker.o: src/lib/input_checker.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/lib/lexer.o: src/lib/lexer.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/lib/parser.o: src/lib/parser.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

bin/testapp.out: obj/test/input_checker_test.o obj/test/lexer_test.o obj/test/parser_test.o obj/test/main.o obj/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/test/input_checker_test.o: test/input_checker_test.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/test/lexer_test.o: test/lexer_test.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/test/parser_test.o: test/parser_test.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/test/main.o: test/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

.PHONY: test

test: bin/testapp.out
	./bin/testapp.out

clean:
	# rm obj/test/*.*
	rm obj/lib/*.*
	rm bin/*.out
	rm bin/*.d
	