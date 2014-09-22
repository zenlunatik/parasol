CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lm

sessions.o : sessions.cc sessions.h
	${CC} ${CFLAGS} -c sessions.cc

main.o : main.cc sessions.h
	${CC} ${CFLAGS} -c main.cc

dbif : main.o sessions.o
	${CC} ${CFLAGS} sessions.o main.o ${LDFLAGS} -o dbif
