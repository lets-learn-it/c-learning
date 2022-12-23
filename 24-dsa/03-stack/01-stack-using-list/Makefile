CC=gcc
CCFLAGS=-c -Wall -O3
EXEC=stack.out
EXECFLAGS=-d

# NOTES
# $< first dependent
# $@ target

all: TARGET

TARGET: $(EXEC)

$(EXEC): *.o
	$(CC) *.o -o $@

*.o: *.c
	@echo "compiling..."
	$(CC) $(CCFLAGS) *.c
	@echo "compiled!!"

clean:
	rm -rf *.o *.out

run: $(EXEC)
	./$< $(EXECFLAGS)