OBJECTS = main.o binary_search_tree.o
CC = gcc


bst: $(OBJECTS)
	$(CC) -o bst $(OBJECTS)

main.o: main.c binary_search_tree.h
	$(CC) -c main.c

binary_tree.o: binary_search_tree.c binary_search_tree.h
	$(CC) -c binary_search_tree.c

.PHONY = clean

clean:
	rm -f bst main.o binary_search_tree.o