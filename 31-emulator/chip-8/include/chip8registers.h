#ifndef CHIP8_REGISTERS
#define CHIP8_REGISTERS

#include "chip8config.h"

struct chip8_registers {
  unsigned char V[CHIP8_TOTAL_DATA_REGISTERS];  /* general purpose registers */
  unsigned short I;                             /* 16 bit used for storing memory address */
  unsigned char delay_timer;
  unsigned char sound_timer;
  unsigned short PC;  /* program counter */
  unsigned char SP;   /* stack pointer */
};

#endif