default:
	make build && \
		rm -rf *.o && \
		./lexer
build:
	g++ \
		-g \
		-std=c++20 \
		main.cpp \
		-o lexer

clean:
	rm -rf lexer.dSYM lexer *.o
