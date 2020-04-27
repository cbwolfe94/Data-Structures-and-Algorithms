OBJECTS = main.o queue.o
CC = gcc
FLAGS = -Werror -Wall

queue: $(OBJECTS)
	$(CC) -o queue $(OBJECTS)

queue.o: queue.c queue.h
	$(CC) -c queue.c $(FLAGS)

main.o: main.c queue.h
	$(CC) -c main.c $(FLAGS)

.PHONY = clean
clean:
	rm -f queue *.o
