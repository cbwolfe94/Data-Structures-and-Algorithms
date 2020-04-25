objects = main.o stack.o
CC = g++

stack: $(objects)
	$(CC) -o stack $(objects)

stack.o: stack.cpp stack.h
	$(CC) -c stack.cpp

main.o: main.cpp stack.h
	$(CC) -c main.cpp

.PHONY = clean
clean:
	rm -f stack *.o
