OBJECTS = main.o binary_tree.o
CC = gcc


tree: $(OBJECTS)
	$(CC) -o tree $(OBJECTS)

main.o: main.c binary_tree.h
	$(CC) -c main.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) -c binary_tree.c

.PHONY = clean

clean:
	rm -f tree main.o binary_tree.o