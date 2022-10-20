# call assembly function from C

## Compile & Assemble C code

```sh
gcc -c main.c -o main.o
```

## Assemble assembly code

```sh
nasm -f elf64 function.asm
```

## Link

```sh
gcc main.o function.o
```

## Run Executable

```sh
./a.out
```