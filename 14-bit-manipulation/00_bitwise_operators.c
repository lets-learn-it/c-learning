#include<stdio.h>
#include<stdint.h>

#define bits(x) sizeof(x)*8

int main() {
  uint8_t a = 0xf0;
  uint8_t b = 0x06;
  uint8_t temp;

  printf("Number of bits: %lu\n", bits(a));
  // NOT (~)
  temp = ~a;
  printf("NOT %x  : %x\n", a, temp);

  // AND (&)
  temp = a&b;
  printf("%x AND %x: %x\n", a, b, temp);

  // OR (|)
  temp = a|b;
  printf("%x OR %x : %x\n", a, b, temp);

  // XOR (^)
  temp = a^b;
  printf("%x XOR %x: %x\n", a, b, temp);

  // LEFT SHIFT (x<<shifts)
  temp = a<<2;
  printf("%x << 2 : %x\n", a, temp);

  // RIGHT SHIFT (x>>shifts)
  temp = b<<2;
  printf("%x << 2  : %x\n", b, temp);

  return 0;
}