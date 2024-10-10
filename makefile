FLAGS = -g
#FLAGS = -O2

all: test_Queue test_Jug

test_Queue: State.o Queue.o test_Queue.cpp
	g++ ${FLAGS} State.o Queue.o test_Queue.cpp -o test_Queue

test_Jug: State.o Queue.o Hash.o Jug.o test_Jug.cpp
	g++ ${FLAGS} State.o Queue.o Hash.o Jug.o test_Jug.cpp -o test_Jug

State.o: State.h State.cpp
	g++ ${FLAGS} -c State.cpp

Hash.o: Hash.h Hash.cpp
	g++ ${FLAGS} -c Hash.cpp

Queue.o: Queue.h Queue.cpp
	g++ ${FLAGS} -c Queue.cpp

Jug.o: Jug.h Jug.cpp
	g++ ${FLAGS} -c Jug.cpp

clean:
	rm -f *.o test_Queue test_Jug
