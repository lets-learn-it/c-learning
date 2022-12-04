#include <stdio.h>
#include <stdbool.h>

/********************************************** 
 * This Example taken from:
 * https://www.youtube.com/watch?v=b9_0bqrm2G8
 **********************************************/

typedef struct character {
  char *name;
  bool isrobot;
  union {
    char *personality;
    int firmware_version;
  };
} character;

void print_character(character *c) {
  printf("Name: %s\n", c->name);
  if (c->isrobot) {
    printf("Firmware version: %d\n", c->firmware_version);
  } else {
    printf("Personality: %s\n", c->personality);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  character hansolo, r2d2;

  hansolo.name = "Han Solo";
  hansolo.isrobot = false;
  hansolo.personality = "XXXXXX";

  r2d2.name = "R2 D2";
  r2d2.isrobot = true;
  r2d2.firmware_version = 42;

  print_character(&hansolo);
  print_character(&r2d2);

  return 0;
}

