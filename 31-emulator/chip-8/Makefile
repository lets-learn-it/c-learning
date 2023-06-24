INCLUDES= -I ./include
FLAGS= -g
LDFLAGS=`sdl2-config --cflags --libs`

OBJECTS=./build/chip8memory.o ./build/chip8stack.o ./build/chip8keyboard.o ./build/chip8.o ./build/chip8screen.o

all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} -o ./bin/main ${LDFLAGS}

./build/chip8memory.o:src/chip8memory.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8memory.c -c -o ./build/chip8memory.o

./build/chip8stack.o:src/chip8stack.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8stack.c -c -o ./build/chip8stack.o

./build/chip8keyboard.o:src/chip8keyboard.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8keyboard.c -c -o ./build/chip8keyboard.o

./build/chip8.o:src/chip8.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8.c -c -o ./build/chip8.o

./build/chip8screen.o:src/chip8screen.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8screen.c -c -o ./build/chip8screen.o

clean:
	rm build/* -f
	rm bin/* -f