OBJECTS = main.o hash.o
CC = gcc

hash: $(OBJECTS)
	$(CC) -o hash $(OBJECTS)

hash.o: hash.c hash.h
	$(CC) -c hash.c

main.o: main.c hash.h
	$(CC) -c main.c

.PHONY=clean
clean:
	rm -f hash *.o 
