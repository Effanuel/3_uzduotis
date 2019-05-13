CXX = g++
CC = gcc
CFLAGS = -std=c++11

.PHONY: all project clean

all: project

project: 3_uzduotis.o Studentas.o
	$(CXX) -o project 3_uzduotis.o Studentas.o

3_uzduotis.o: 3_uzduotis.cpp
	$(CXX) $(CFLAGS) -c 3_uzduotis.cpp -o 3_uzduotis.o

Studentas.o: Studentas.cpp
	$(CXX) $(CFLAGS) -c Studentas.cpp -o Studentas.o

test:	all
	./project

clean:
	rm -f project *.o project.exe
