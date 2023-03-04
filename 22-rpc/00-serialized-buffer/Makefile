CC=gcc
CCFLAGS=-c -Wall -g
EXEC=sbuff.out
EXECFLAGS=-d
INCLUDES=-I./

# NOTES
# $< first dependent
# $@ target

all: TARGET

TARGET: $(EXEC)

$(EXEC): *.o
	$(CC) *.o -o $@ -g

*.o:*.c
	$(CC) $(CCFLAGS) $(INCLUDES) *.c

clean:
	rm -rf *.o *.out

run: $(EXEC)
	./$< $(EXECFLAGS)