exec = tac.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%h
	gcc -c $(flags) $< -o $@

clean:
	rm *.out src/*.o

lint:
	clang-tidy src/*.c src/include/*.h
