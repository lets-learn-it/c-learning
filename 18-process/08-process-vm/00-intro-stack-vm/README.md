# Simple Stack based VM

**Example** Print 1 + 2

```
iconst 1 stack=[ 1 ]
iconst 2 stack=[ 1 2 ]
iadd     stack=[ 3 ]
print    stack=[ ]
halt     stack=[ ]
```

## Instruction Set

```
iadd                 Integer add (pop 2 operands, add, push result)
isub
imul
ilt                  integer less than
ieq
br addr              branch to address
brt addr             branch if true
iconst value         push integer constant
load addr            load local
global addr          load global variable
store addr
gstore addr
print
pop                  toss out the top of stack
call addr, numArgs   call addr, expect numArgs
ret                  return from function, expected result on top stack
halt
```

## Instruction Format

```
bytecode
bytecode operand
bytecode operand1 operand2
```

- Code memory is 32-bit addressable
- Bytecodes stored as ints but they are bytes
- Data memory is 32 bit word addressable
- Addresses are just integer numbers
- Operands are 32 bit integers.

## Fetch-Decode-Execute

```
fetch: opcode = code[ip]
decode: switch (opcode) {...}
execute: stack[++sp] = stack[sp--] + stack[sp--] // add instruction
```

## References

[[00] https://www.youtube.com/watch?v=OjaAToVkoTw&list=LL&index=2&t=8s](https://www.youtube.com/watch?v=OjaAToVkoTw&list=LL&index=2&t=8s)