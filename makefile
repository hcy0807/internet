CC=gcc
CFLAGS=-Wall -ggdb

all: pipe1

pipe1: 
	$(CC) $(CFLAGS) pipe.c -o pipe.o

clean: 
	rm -rf *.o
