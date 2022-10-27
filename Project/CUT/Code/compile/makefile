SRCDIR= ../src
OBJDIR= ../obj
BINDIR= ../bin
REPORTDIR= ../report
CFLAGS= -c -g -Wall 



all:
	gcc ${CFLAGS} ${SRCDIR}/backup.c -o ${OBJDIR}/backup.o
	gcc ${OBJDIR}/backup.o -o ${BINDIR}/backup.bin

memcheck:
	valgrind ${BINDIR}/backup.bin > ${REPORTDIR}/memcheck.txt 2>&1
