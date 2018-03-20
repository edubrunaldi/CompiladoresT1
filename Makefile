ARGS ?= "entradas/0.C"

.PHONY: all
all:
	mkdir -p bin build
	flex -o build/lex.yy.h src/lexer.l
	gcc src/*.c -o bin/gcc- -I build -I src -lfl -Wall -Wextra

.PHONY: clean
clean:
	rm build/*

# make run ARGS="parametros do parser"
.PHONY: run
run:
	./bin/gcc- ${ARGS}
