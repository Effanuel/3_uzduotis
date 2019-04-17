CXX = g++
CC = gcc
CFLAGS = -std=c++11

.PHONY: all project clean

all: project

project: 3_uzduotis.o Mano_func.o Studentas.o
	$(CXX) -o project 3_uzduotis.o Mano_func.o Studentas.o


3_uzduotis.o: 3_uzduotis.cpp
	$(CXX) $(CFLAGS) -c 3_uzduotis.cpp -o 3_uzduotis.o


Mano_func.o: Mano_func.cpp
	$(CXX) $(CFLAGS) -c Mano_func.cpp -o Mano_func.o


Algoritmai.o: Studentas.cpp
	$(CXX) $(CFLAGS) -c Studentasi.cpp -o Studentas.o

test:	all
	./3_uzduotis

clean:
	rm -f project *.o project.exe
