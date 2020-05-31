CC = g++
CFLAGS = -Werror -Wall
DIR = `basename $(CURDIR)`

all: main

main: main.o dynamicarray.hpp
	$(CC) $(CFLAGS) main.o dynamicarray.hpp -o main

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

#dynamicarray.o: dynamicarray.cpp dynamicarray.h
#	$(CC) $(CFLAGS) -c dynamicarray.cpp


tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

clean:
	rm -f *.o main