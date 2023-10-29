default: compile-dates compile-logger
	make build && \
		rm -rf *.o && \
		./lexer

compile-dates:
	clang++ \
		-g \
		-std=c++20 \
		-c lib/dates/dates.cpp \
		-o dates.o

compile-logger:
	clang++ \
		-g \
		-std=c++20 \
		-c lib/logger/logger.cpp \
		-o logger.o

build:
	clang++ \
		-g \
		-std=c++20 \
		main.cpp *.o \
		-o lexer

clean:
	rm -rf lexer.dSYM lexer *.o
