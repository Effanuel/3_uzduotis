CXX = g++
CC = gcc
CFLAGS = -std=c++11

.PHONY: all project clean

all: project

project: DuomenuApdorojimas.o Mano_func.o 
	$(CXX) -o project DuomenuApdorojimas.o Mano_func.o 


DuomenuApdorojimas.o: DuomenuApdorojimas.cpp
	$(CXX) $(CFLAGS) -c DuomenuApdorojimas.cpp -o DuomenuApdorojimas.o 


test:	all
	./project

clean:
	rm -f project *.o project.exe
