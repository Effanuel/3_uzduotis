CXX = g++
CC = gcc
CFLAGS = -std=c++11

.PHONY: all project clean

all: project

project: DuomenuApdorojimas.o Mano_func.o Algoritmai.o
	$(CXX) -o project DuomenuApdorojimas.o Mano_func.o Algoritmai.o


DuomenuApdorojimas.o: DuomenuApdorojimas.cpp
	$(CXX) $(CFLAGS) -c DuomenuApdorojimas.cpp -o DuomenuApdorojimas.o 


Mano_func.o: Mano_func.cpp
	$(CXX) $(CFLAGS) -c Mano_func.cpp -o Mano_func.o 


Algoritmai.o: Algoritmai.cpp
	$(CXX) $(CFLAGS) -c Algoritmai.cpp -o Algoritmai.o

test:	all
	./DuomenuApdorojimas

clean:
	rm -f project *.o project.exe
