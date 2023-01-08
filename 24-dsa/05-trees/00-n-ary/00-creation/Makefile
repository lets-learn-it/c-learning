CC=gcc
CCFLAGS=-c -Wall -g
EXEC=tree.out
EXECFLAGS=-d
INCLUDES=-I./../../../02-linked-lists/01-doubly-linked-list/ -I./../../../04-queues/01-queue-using-list/
DLL=./../../../02-linked-lists/01-doubly-linked-list/dll.c
QUEUE=./../../../04-queues/01-queue-using-list/queue.c

# NOTES
# $< first dependent
# $@ target

all: TARGET

TARGET: $(EXEC)

$(EXEC): *.o
	$(CC) *.o -o $@ -g

*.o:*.c
	$(CC) $(CCFLAGS) $(INCLUDES) *.c
	$(CC) $(CCFLAGS) $(DLL) $(QUEUE) $(INCLUDES)

clean:
	rm -rf *.o *.out

run: $(EXEC)
	./$< $(EXECFLAGS)