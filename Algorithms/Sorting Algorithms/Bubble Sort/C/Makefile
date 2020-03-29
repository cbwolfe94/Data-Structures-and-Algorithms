bubble: bubble.o main.o
	gcc -o bubble bubble.o main.o

bubble.o: bubble.c bubble.h
	gcc -c bubble.c bubble.h

main.o: main.c bubble.h
	gcc -c main.c
