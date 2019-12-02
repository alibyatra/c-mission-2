#!make -f

CC=gcc
OBJECTS_MAIN=myBank.o main.o
FLAGS= -Wall -g -fPIC

all: main	

main: $(OBJECTS_MAIN)

	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN)

myBank.o: myBank.h

	$(CC) $(FLAGS) -c myBank.c

main.o: myBank.h 

	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o main
