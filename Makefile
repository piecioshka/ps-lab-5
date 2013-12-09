CC = gcc
CFLAGS = -Wall -Werror -pedantic -pedantic-errors
TARGET = bin/
SRC = source/

zad1:
	${CC} ${CFLAGS} ${SRC}$@/system.c -o ${TARGET}$@/system.o

clean:
	find . -name "*.o" | xargs rm

