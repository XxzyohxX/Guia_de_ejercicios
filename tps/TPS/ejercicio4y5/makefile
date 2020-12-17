PROGRAM=tp5
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g

all: $(PROGRAM)
$(PROGRAM): midi.o main.o
	$(CC) $(CFLAGS) midi.o main.o -o $(PROGRAM)
midi.o: midi.c  midi.h
	$(CC) $(CFLAGS) -c midi.c
main.o: main.c midi.h
	$(CC) $(CFLAGS) -c main.c
clear:
	rm *.o