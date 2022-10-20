section .data
  string  db  "Oh, no! This line repeats",0x0a
  string_len equ $-string

  STDOUT equ 1
  SYS_write equ 1

section .bss
section .text
  global message

message:
  mov rsi, string
  mov rdx, string_len
  mov rdi, STDOUT
  mov rax, SYS_write
  syscall
  ret
  