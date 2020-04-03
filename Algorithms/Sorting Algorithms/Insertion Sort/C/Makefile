insertion: main.o insertion.o
	gcc -o insertion main.o insertion.o

insertion.o: insertion.c insertion.h
	gcc -c insertion.c

main.o: main.c insertion.h
	gcc -c main.c
