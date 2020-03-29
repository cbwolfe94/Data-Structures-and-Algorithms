bubble: main.o bubble.o
	g++ -o bubble main.o bubble.o

bubble.o: bubble.cpp bubble.h
	g++ -c bubble.cpp bubble.h

main.o: main.cpp bubble.h
	g++ -c main.cpp 
