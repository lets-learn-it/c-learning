CC=gcc
CCFLAGS=-c -Wall -O3
EXEC=app.out
EXECFLAGS=-d
INCLPATHS=
GENOUT=output.gen.txt

test: $(GENOUT)
	diff -s output.txt $(GENOUT)

$(GENOUT): $(EXEC)
	./$(EXEC)

$(EXEC): *.o
	$(CC) *.o -o $@

*.o: *.c
	@echo "compiling..."
	$(CC) $(CCFLAGS) *.c
	@echo "compiled!!"

clean:
	rm -rf *.o *.out *.gen.txt

