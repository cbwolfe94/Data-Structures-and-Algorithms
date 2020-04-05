objects = main.o merge.o
CC = g++

merge: $(objects)
	$(CC) -o merge $(objects)

merge.o: merge.cpp merge.h
	$(CC) -c merge.cpp

main.o: main.cpp merge.h
	$(CC) -c main.cpp

.PHONY: clean
clean: 
	rm -f *.o merge
