CC = gcc
CFLAGS = -Wall -Werror -pedantic -pedantic-errors
TARGET = bin/
SRC = source/

zad1:
	${CC} ${CFLAGS} ${SRC}$@/system.c -o ${TARGET}$@/system.o

zad2:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad3:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad4:
	${CC} ${CFLAGS} ${SRC}$@/shell.c -o ${TARGET}$@/shell.o

zad5:
	${CC} ${CFLAGS} ${SRC}$@/sigcatch.c -o ${TARGET}$@/sigcatch.o
	${CC} ${CFLAGS} ${SRC}$@/raise.c -o ${TARGET}$@/raise.o

zad6:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad7:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad8:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad9:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad10:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad11:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad12:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad13:
	${CC} ${CFLAGS} ${SRC}$@/sig_reciver.c -o ${TARGET}$@/sig_reciver.o
	${CC} ${CFLAGS} ${SRC}$@/sig_sender.c -o ${TARGET}$@/sig_sender.o

clean:
	find . -name "*.o" | xargs rm

