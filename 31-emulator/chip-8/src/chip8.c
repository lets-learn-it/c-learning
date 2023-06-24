#include "chip8.h"
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

const char chip8_default_character_set[] = {
  0xf0, 0x90, 0x90, 0x90, 0xf0,    /* 0 */
  0x20, 0x60, 0x20, 0x20, 0x70,    /* 1 */
  0xf0, 0x10, 0xf0, 0x80, 0xf0,    /* 2 */
  0xf0, 0x10, 0xf0, 0x10, 0xf0,    /* 3 */
  0x90, 0x90, 0xf0, 0x10, 0x10,    /* 4 */
  0xf0, 0x80, 0xf0, 0x10, 0xf0,    /* 5 */
  0xf0, 0x80, 0xf0, 0x90, 0xf0,    /* 6 */
  0xf0, 0x10, 0x20, 0x40, 0x40,    /* 7 */
  0xf0, 0x90, 0xf0, 0x90, 0xf0,    /* 8 */
  0xf0, 0x90, 0xf0, 0x10, 0xf0,    /* 9 */
  0xf0, 0x90, 0xf0, 0x90, 0x90,    /* A */
  0xe0, 0x90, 0xe0, 0x90, 0xe0,    /* B */
  0xf0, 0x80, 0x80, 0x80, 0xf0,    /* C */
  0xe0, 0x90, 0x90, 0x90, 0xe0,    /* D */
  0xf0, 0x80, 0xf0, 0x80, 0xf0,    /* E */
  0xf0, 0x80, 0xf0, 0x80, 0x80     /* F */
};

void chip8_init(struct chip8* chip) {
  memset(chip, 0, sizeof(struct chip8));

  /* 
   * copy character set in memory
   * it starts from 0x00 (from start)
   */
  memcpy(&chip->memory.memory, chip8_default_character_set, sizeof(chip8_default_character_set));
}

void chip8_load(struct chip8* chip8, const char* buf, size_t size) {
  assert(size+CHIP8_PROGRAM_LOAD_ADDRESS < CHIP8_MEMORY_SIZE);

  memcpy(&chip8->memory.memory[CHIP8_PROGRAM_LOAD_ADDRESS], buf, size);
  chip8->registers.PC = CHIP8_PROGRAM_LOAD_ADDRESS;
}

static void chip8_exec_extended_eight(struct chip8* chip8, unsigned short opcode) {
  unsigned char x = (opcode & 0x0f00) >> 8;
  unsigned char y = (opcode & 0x00f0) >> 4;
  unsigned char final_fourbits = opcode & 0x000f;

  switch (final_fourbits) {
  case 0x00:  /* 8xy0 - LD Vx, Vy  (set Vx = Vy) */
    chip8->registers.V[x] = chip8->registers.V[y];
    break;
  
  case 0x01:  /* 8xy1 - OR Vx, Vy  (set Vx = Vx OR Vy) */
    chip8->registers.V[x] |= chip8->registers.V[y];
    break;

  case 0x02:  /* 8xy2 - AND Vx, Vy  (set Vx = Vx AND Vy) */
    chip8->registers.V[x] &= chip8->registers.V[y];
    break;

  case 0x03:  /* 8xy3 - XOR Vx, Vy  (set Vx = Vx XOR Vy) */
    chip8->registers.V[x] ^= chip8->registers.V[y];
    break;

  case 0x04:  /* 8xy4 - ADD Vx, Vy  (set Vx = Vx + Vy, set VF = carry) */
    chip8->registers.V[x] += chip8->registers.V[y];
    chip8->registers.V[0x0f] = chip8->registers.V[x] > 0xff;
    break;

  case 0x05:  /* 8xy5 - SUB Vx, Vy  (set Vx = Vx - Vy, set VF if Vx > Vy) */
    chip8->registers.V[x] -= chip8->registers.V[y];
    chip8->registers.V[0x0f] = chip8->registers.V[x] > chip8->registers.V[y];
    break;

  case 0x06: /* 8xy6 - SHR Vx {, Vy}  (Set Vx = Vx SHR 1) 
                If least significant bit of Vx is 1, set VF to 1 otherwise 0 */
    chip8->registers.V[0x0f] = chip8->registers.V[x] & 0x01;
    chip8->registers.V[x] /= 2;
    break;

  case 0x07:  /* 8xy7 - SUBN Vx, Vy (set Vx = Vy - Vx, set VF if Vy > Vx) */
    chip8->registers.V[x] = chip8->registers.V[y] - chip8->registers.V[x];
    chip8->registers.V[0x0f] = chip8->registers.V[x] < chip8->registers.V[y];
    break;

  case 0x0E:  /* 8xyE - SHL Vx {, Vy}  (Set Vx = Vx SHL 1) 
                 if most significant bit of Vx is 1, set VF to 1 otherwise 0 */
    chip8->registers.V[0x0f] = chip8->registers.V[x] & 0x80;
    chip8->registers.V[x] *= 2;
    break;
  }
}

static char chip8_wait_for_key_press(struct chip8* chip8) {
  SDL_Event event;

  while(SDL_WaitEvent(&event)) {
    if (event.type != SDL_KEYDOWN) continue;
    char c = event.key.keysym.sym;
    char chip8_key = chip8_keyboard_map(&chip8->keyboard, c);
    if (chip8_key != -1) return chip8_key;
  }
  return -1;
}

static void chip8_exec_extended_F(struct chip8* chip8, unsigned short opcode) {
  unsigned char x = (opcode & 0x0f00) >> 8;

  switch (opcode & 0x00ff) {
  case 0x07:  /* Fx07 - LD Vx, DT  (set Vx = delay timer value) */
    chip8->registers.V[x] = chip8->registers.delay_timer;
    break;
  
  case 0x0A:  /* Fx0A - LD Vx, K (wait for key press, store value in Vx) */
    chip8_wait_for_key_press(chip8);
    break;
  
  case 0x15:  /* Fx15 - LD DT, Vx ( set delay timer = Vx) */
    chip8->registers.delay_timer = chip8->registers.V[x];
    break;

  case 0x18:  /* Fx18 - LD ST, Vx  (set sound timer = Vx) */
    chip8->registers.sound_timer = chip8->registers.V[x];
    break;

  case 0x1E:  /* Fx1E - Add I, Vx  (set I = I + Vx) */
    chip8->registers.I += chip8->registers.V[x];
    break;

  case 0x29:  /* Fx29 - LD F, Vx  (set I = location of sprite for digit Vx) */
    chip8->registers.I = chip8->registers.V[x] * CHIP8_DEFAULT_SPRITE_HEIGHT;
    break;

  case 0x33:  /* Fx33 - LD B, Vx  (store BCD representation of Vx in memory location I, I+1 and I+2) */
    chip8_memory_set(&chip8->memory, chip8->registers.I, chip8->registers.V[x] / 100);
    chip8_memory_set(&chip8->memory, chip8->registers.I+1, chip8->registers.V[x] / 10 % 10);
    chip8_memory_set(&chip8->memory, chip8->registers.I+2, chip8->registers.V[x] % 10);
    break;

  case 0x55:  /* Fx55 - LD [I], Vx  (store registers V0 through Vx in memory starting at location I) */
    for (int i=0;i<=x;i++) {
      chip8_memory_set(&chip8->memory, chip8->registers.I+i, chip8->registers.V[i]);
    }
    break;

  case 0x65:  /* Fx65 - LD Vx, [I]  (read registers V0 through Vx from memory starting at location I) */
    for (int i=0;i<=x;i++) {
      chip8->registers.V[i] = chip8_memory_get(&chip8->memory, chip8->registers.I+i);
    }
    break;
  }
}

static void chip8_exec_extended(struct chip8* chip8, unsigned short opcode) {
  unsigned short nnn = opcode & 0x0fff;
  unsigned char x = (opcode & 0x0f00) >> 8;
  unsigned char y = (opcode & 0x00f0) >> 4;
  unsigned char kk = opcode & 0x00ff;
  unsigned char n = opcode & 0x000f;

  switch (opcode & 0xf000) {
  case 0x1000:  /* 1nnn - JP addr  (jump to location nnn) */
    chip8->registers.PC = nnn;
    break;
  
  case 0x2000:  /* 2nnn - CALL addr  (call subroutine at nnn) */
    chip8_stack_push(chip8, chip8->registers.PC);
    chip8->registers.PC = nnn;
    break;

  case 0x3000:  /* 3xkk - SE Vx, byte (skip next instruction if Vx == kk) */
    if (chip8->registers.V[x] == kk) chip8->registers.PC += 2;
    break;
  
  case 0x4000:  /* 4xkk - SNE Vx, byte (skip next instruction if Vx != kk) */
    if (chip8->registers.V[x] != kk) chip8->registers.PC += 2;
    break;
  
  case 0x5000:  /* 5xy0 - SE Vx, Vy  (skip next instruction if Vx == Vy) */
    if (chip8->registers.V[x] == chip8->registers.V[y]) chip8->registers.PC += 2;
    break;

  case 0x6000:  /* 6xkk - LD Vx, byte  (Set Vx = kk) */
    chip8->registers.V[x] = kk;
    break;
  
  case 0x7000: /* 7xkk - ADD Vx, byte (set Vx = Vx + kk) */
    chip8->registers.V[x] += kk;
    break;
  
  case 0x8000:
    chip8_exec_extended_eight(chip8, opcode);
    break;
  
  case 0x9000:  /* 9xy0 - SNE Vx, Vy  (skip next instruction if Vx != Vy) */
    if (chip8->registers.V[x] != chip8->registers.V[y]) chip8->registers.PC += 2;
    break;

  case 0xA000:  /* Annn - LD I, addr (set I = nnn) */
    chip8->registers.I = nnn;
    break;
  
  case 0xB000:  /* Bnnn - JP V0, addr (Jump to location nnn + V0) */
    chip8->registers.PC = nnn + chip8->registers.V[0x00];
    break;
  
  case 0xC000:  /* Cxkk - RND Vx, byte  (Set Vx = random byte AND kk) */
    srand(clock());
    chip8->registers.V[x] = (rand() % 255) & kk;
    break;

  case 0xD000:  /* Dxyn - DRW Vx, Vy, nibble  
                  (Display n byte sprite starting at memory location I at (Vx, Vy), set VF = collision */
    const char* sprite = (const char*) &chip8->memory.memory[chip8->registers.I];
    chip8->registers.V[0xf0] = chip8_screen_draw_sprite(&chip8->screen, 
      chip8->registers.V[x],
      chip8->registers.V[y],
      sprite, n );
    break;

  case 0xE000:  
    switch (opcode & 0x00ff) {
    case 0x009E: /* Ex9E - SKP Vx  (skip next instruction if key with value of Vx is pressed) */
      if (chip8_keyboard_is_down(&chip8->keyboard, chip8->registers.V[x])) chip8->registers.PC += 2;
      break;
    
    case 0x00A1: /* ExA1 - SKNP Vx  (skip next instruction if key with value of Vx is not pressed) */
      if (!chip8_keyboard_is_down(&chip8->keyboard, chip8->registers.V[x])) chip8->registers.PC += 2;
      break;
    }
    break;
  
  case 0xF000:
    chip8_exec_extended_F(chip8, opcode);
    break;
  }
}

void chip8_exec(struct chip8* chip8, unsigned short opcode) {
  switch (opcode) {
  case 0x00E0:  /* CLS: clear screen */
    chip8_screen_clear(&chip8->screen);
    break;
  case 0x00EE: /* RET: return from subroutine */
    chip8->registers.PC = chip8_stack_pop(chip8);
    break;
  default:
    chip8_exec_extended(chip8, opcode);
  }
}
