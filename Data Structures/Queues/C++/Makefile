OBJECTS = main.o queue.o
CXX = g++
FLAGS = -Werror -Wall

queue: $(OBJECTS)
	$(CXX) -o queue $(OBJECTS) $(FLAGS)

queue.o: queue.cpp queue.h
	$(CXX) -c queue.cpp

main.o: main.cpp queue.h
	$(CXX) -c main.cpp

.PHONY = clean
clean:
	rm -f queue *.o

