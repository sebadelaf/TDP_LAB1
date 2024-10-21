# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Archivos de clase
OBJ = Jug.o State.o Queue.o Operation.o Hash.o

# Target para compilar el programa principal
all: main

# Compilar el programa principal
main: main.o $(OBJ)
	$(CXX) $(CXXFLAGS) -o main main.o $(OBJ)

# Reglas para compilar cada clase .cpp en su respectivo .o
Jug.o: Jug.cpp Jug.h Operation.h Queue.h Hash.h
	$(CXX) $(CXXFLAGS) -c Jug.cpp

State.o: State.cpp State.h
	$(CXX) $(CXXFLAGS) -c State.cpp

Queue.o: Queue.cpp Queue.h State.h
	$(CXX) $(CXXFLAGS) -c Queue.cpp

Operation.o: Operation.cpp Operation.h State.h
	$(CXX) $(CXXFLAGS) -c Operation.cpp

Hash.o: Hash.cpp Hash.h State.h
	$(CXX) $(CXXFLAGS) -c Hash.cpp

# Compilar el archivo principal
main.o: main.cpp Jug.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Limpiar los archivos generados
clean:
	rm -f *.o main
