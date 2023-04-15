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
  {"CALL", 2},
  {"RET", 0},
  {"HALT", 0}
};

void init(VM *vm, int *code, int code_length, int main) {
  vm->code = code;
  vm->code_length = code_length;
  vm->ip = main;
  vm->sp = -1;
  vm->fp = -1;
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
  int addr = 0, v = 0, offset = 0, nargs = 0, rvalue = 0, a = 0, b = 0;
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
        b = vm->stack[vm->sp--];
        a = vm->stack[vm->sp--];
        vm->stack[++vm->sp] = a + b;
        break;
      case ISUB:
        b = vm->stack[vm->sp--];
        a = vm->stack[vm->sp--];
        vm->stack[++vm->sp] = a - b;
        break;
      case IMUL:
        b = vm->stack[vm->sp--];
        a = vm->stack[vm->sp--];
        vm->stack[++vm->sp] = a * b;
        break;
      case ILT:
        b = vm->stack[vm->sp--];
        a = vm->stack[vm->sp--];
        vm->stack[++vm->sp] = (a < b) ? TRUE : FALSE;
        break;
      case IEQ:
        b = vm->stack[vm->sp--];
        a = vm->stack[vm->sp--];
        vm->stack[++vm->sp] = (a == b) ? TRUE : FALSE;
        break;
      case BR:
        vm->ip = vm->code[vm->ip++];
        break;
      case BRT:  /* branch true */
        addr = vm->code[vm->ip++];
        if ( vm->stack[vm->sp--] == TRUE ) vm->ip = addr;
        break;
      case BRF:  /* branch false */
        addr = vm->code[vm->ip++];
        if ( vm->stack[vm->sp--] == FALSE ) vm->ip = addr;
        break;
      case LOAD:  /* load local/args in function */
        offset = vm->code[vm->ip++];
        vm->stack[++vm->sp] = vm->stack[vm->fp + offset];
        break;
      case CALL:
        /* expect all args on stack */
        addr = vm->code[vm->ip++];       /* target addr of function */
        nargs = vm->code[vm->ip++];      /* how many args got pushed */
        vm->stack[++vm->sp] = nargs;     /* save num args */
        vm->stack[++vm->sp] = vm->fp;    /* save fp (frame pointer) */
        vm->stack[++vm->sp] = vm->ip;    /* save instruction pointer */
        vm->fp = vm->sp;                 /* fp points at ret addr on stack */
        vm->ip = addr;                   /* jump to function */
        break;
      case RET:
        rvalue = vm->stack[vm->sp--];    /* pop return value */
        vm->sp = vm->fp;                 /* jump over locals to fp which points to sp before call */
        vm->ip = vm->stack[vm->sp--];    /* pop return address, jump to it */
        vm->fp = vm->stack[vm->sp--];    /* restore fp */
        nargs = vm->stack[vm->sp--];     /* how many args to throw away */
        vm->sp -= nargs;                 /* pop args */
        vm->stack[++vm->sp] = rvalue;    /* leave result on stack */
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