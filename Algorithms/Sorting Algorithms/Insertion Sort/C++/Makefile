insertion: main.o insertion.o
	g++ -o insertion main.o insertion.o

insertion.o: insertion.cpp insertion.h
	g++ -c insertion.cpp insertion.h

main.o: main.cpp insertion.h
	g++ -c main.cpp

clean:
	rm -f insertion main.o insertion.o 
