#include "vm.h"
#include <stdio.h>

Instruction opcodes[] = {
  {"IADD", 0},
  {"ISUB", 0},
  {"IMUL", 0},
  {"ILT", 0},
  {"IEQ", 0},
  {"BR", 1},
  {"BRT", 1},
  {"BRF", 1},
  {"ICONST", 1},
  {"LOAD", 1},
  {"GLOAD", 1},
  {"STORE", 1},
  {"GSTORE", 1},
  {"PRINT", 0},
  {"POP", 0},
  {"HALT", 0}
};

void init(VM *vm, int *code, int code_length, int main) {
  vm->code = code;
  vm->code_length = code_length;
  vm->ip = main;
  vm->sp = -1;
  vm->trace = 0;
}

void trace(VM * vm, int trace) {
  vm->trace = trace;
}

void print(VM *vm, int opcode) {
  printf("%04d: %s", vm->ip, opcodes[opcode].opcode);
  if (opcodes[opcode].operands == 1) {
    printf(" %d", vm->code[vm->ip + 1]);
  } else if (opcodes[opcode].operands == 2) {
    printf(" %d %d", vm->code[vm->ip + 1], vm->code[vm->ip + 2]);
  }

  // print stack
  printf("\tstack=[ ");
  for (int i=0;i<=vm->sp;i++) {
    printf("%d ", vm->stack[i]);
  }
  printf("]\n");
}

void cpu(VM *vm) {
  int opcode = vm->code[vm->ip];
  int addr = 0, v = 0;
  while(vm->ip < vm->code_length) {
    if (vm->trace) {
      print(vm, opcode);
    }
    vm->ip++;
    switch (opcode) {
      case ICONST:
        v = vm->code[vm->ip++];
        vm->stack[++vm->sp] = v;
        break;
      case PRINT:
        v = vm->stack[vm->sp];
        vm->sp--;
        printf("%d\n", v);
        break;
      case IADD:
        int b = vm->stack[vm->sp--];
        int a = vm->stack[vm->sp--];
        vm->stack[++vm->sp] = a + b;
        break;
      case GLOAD:
        addr = vm->code[vm->ip++];
        v = vm->data[addr];
        vm->stack[++vm->sp] = v;
        break;
      case GSTORE:
        v = vm->stack[vm->sp--];
        addr = vm->code[vm->ip++];
        vm->data[addr] = v;
        break;
      case HALT:
        return;
    }
    opcode = vm->code[vm->ip];
  }
}