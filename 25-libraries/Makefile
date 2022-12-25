.DEFAULT_GOAL := none

CC=gcc
CCFLAGS=-c -Wall -O3
EXEC=app.out
EXECFLAGS=-d

none:
	@echo "Default rule is not available.\nUse either static/dynamic. Stop."
	@exit 

static: clean *.o
	make -C ./lib libdslib.a
	$(CC) *.o -Llib -ldslib -o $(EXEC)

dynamic: clean *.o
	make -C ./lib libdslib.so
	$(CC) *.o -Llib -ldslib -o $(EXEC)

*.o: *.c
	@echo "compiling..."
	$(CC) $(CCFLAGS) *.c
	@echo "compiled!!"

clean:
	rm -rf *.o *.out
	make -C ./lib clean

