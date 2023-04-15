
#define CODE_LENGTH 256
#define TRUE 1
#define FALSE 0

enum bytecode {
  IADD,
  ISUB,
  IMUL,
  ILT,
  IEQ,
  BR,
  BRT,
  BRF,
  ICONST,
  LOAD,
  GLOAD,
  STORE,
  GSTORE,
  PRINT,
  POP,
  CALL,
  RET,
  HALT
};

typedef struct inst {
  char *opcode;
  int operands;
} Instruction;

typedef struct vm {
  int data[256];
  int *code;
  int code_length;
  int stack[256];
  int trace;

  int ip;  /* instruction pointer */
  int sp;  /* stack pointer */
  int fp;  /* function pointer */
} VM;

void init(VM *vm, int *code, int code_length, int main);
void trace(VM * vm, int trace);
void cpu(VM *vm);