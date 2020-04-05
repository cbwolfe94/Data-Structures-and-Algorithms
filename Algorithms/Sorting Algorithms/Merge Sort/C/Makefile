objects = main.o merge.o
CC = gcc

merge: $(objects)
	$(CC) -o merge $(objects)

merge.0: merge.c merge.h
	$(CC) -c merge.c

main.o: main.c merge.h
	$(CC) -c main.c

.PHONY: clean
clean:
	rm -f *.o merge 
