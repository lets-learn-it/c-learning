CC=gcc
CCFLAGS=-c -Wall -O3 -I/usr/include/lua5.3/

# library mostly available at /usr/lib/x86_64-linux-gnu/ or /usr/local/bin/
LFLAGS=-llua5.3
EXEC=main.out
EXECFLAGS=-d

# NOTES
# $< first dependent
# $@ target

all: TARGET

TARGET: $(EXEC)

$(EXEC): *.o
	$(CC) *.o -o $@ $(LFLAGS)

*.o: *.c
	@echo "compiling..."
	$(CC) $(CCFLAGS) *.c
	@echo "compiled!!"

clean:
	rm -rf *.o *.out

run: $(EXEC)
	./$<