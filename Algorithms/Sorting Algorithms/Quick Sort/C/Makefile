objects = main.o quick.o
CC = gcc

quick: $(objects)
	$(CC) -o quick $(objects)

quick.o: quick.c quick.h
	$(CC) -c quick.c

main.o: main.c quick.h
	$(CC) -c main.c

.PHONY=clean
clean:
	rm -f *.o quick
