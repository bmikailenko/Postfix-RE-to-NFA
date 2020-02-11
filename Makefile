CPP = gcc
FLAGS = -Wall -std=c99 -pedantic -g

EXEC = user
OBJS = stack.o nfa.o transitions.o user.o

default:${EXEC}

clean:
	rm -f ${EXEC}
	rm -f *.o

run: ${EXEC}
	./${EXEC}

${EXEC}:${OBJS}
	${CPP} ${FLAGS} -o ${EXEC} ${OBJS}

.c.o:
	${CPP} ${FLAGS} -c $<

stack.o: stack.c stack.h
nfa.o: nfa.c nfa.h
transitions.o: transitions.c transitions.h
user.o: user.c stack.h nfa.h transitions.h
