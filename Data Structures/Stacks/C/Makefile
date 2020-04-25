objects = main.o stack.o
CC = gcc

stack: $(objects)
	$(CC) -o stack $(objects)

stack.o: stack.c stack.h
	$(CC) -c stack.c

main.o: main.c stack.h
	$(CC) -c main.c

.PHONY = clean
clean:
	rm -f stack *.o
