CXX = g++
CC = g

all:	DuomenuApdorojimas Mano_func Algoritmai

test:	all
	./DuomenuApdorojimas

clean:
	rm -f *.o DuomenuApdorojimas
