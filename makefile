CC=gcc
CFLAGS=-Wall -ggdb

all: pipe1 pipe2

pipe1: 
	$(CC) $(CFLAGS) pipe.c -o pipe.o

pipe2:
	$(CC) $(CFLAGS) pipe_process.c -o pipe_process.o
clean: 
	rm -rf *.o
