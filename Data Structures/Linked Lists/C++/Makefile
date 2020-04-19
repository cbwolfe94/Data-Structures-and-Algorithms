objects = main.o linkedlist.o
CC = g++

linked: $(objects)
	$(CC) -o linked $(objects)

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) -c linkedlist.cpp

main.o: main.cpp linkedlist.h
	$(CC) -c main.cpp

.PHONY = clean
clean:
	rm -f *.o linked
