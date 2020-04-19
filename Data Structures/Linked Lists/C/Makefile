objects = main.o linkedlist.o
CC = gcc

linked: $(objects)
	$(CC) -o linked $(objects)

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c

main.o: main.c linkedlist.h
	$(CC) -c main.c

.PHONY = clean
clean:
	rm -f *.o linked
