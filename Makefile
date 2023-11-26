default:
	make build && \
		rm -rf *.o && \
		./lexer

compile-lexer:
	clang++ \
		-g \
		-std=c++20 \
		-c lib/lexer/lexer.cpp \
		-o lexer.o

build:
	clang++ \
		-g \
		-std=c++20 \
		main.cpp \
		-o lexer

clean:
	rm -rf lexer.dSYM lexer *.o
