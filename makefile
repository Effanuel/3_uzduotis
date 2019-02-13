CXX = g++
CC = g

all:	DuomenuApdorojimas

test:	all
	./DuomenuApdorojimas

clean:
	rm -f *.o DuomenuApdorojimas