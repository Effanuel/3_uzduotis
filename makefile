CXX = g++
CC = g

all:	DuomenuApdorojimas Mano_func

test:	all
	./DuomenuApdorojimas

clean:
	rm -f *.o DuomenuApdorojimas
