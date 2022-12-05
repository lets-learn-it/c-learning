#include <stdio.h>
#include <stdlib.h>

/***************************************************
 * Count vowels in text files  
 ***************************************************/

int is_vowel(char c) {
  if(c == 'a' || c == 'A' ||
     c == 'e' || c == 'E' ||
     c == 'i' || c == 'I' ||
     c == 'o' || c == 'O' ||
     c == 'u' || c == 'U')
    return 1;
  return 0;
}

int main(int argc, char const *argv[]) {
  if(argc < 2) {
    fprintf(stderr, "Filename not provided...\n");
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");

  char c;

  if(!file) {
    perror("error");
    return EXIT_FAILURE;
  }

  int vowel_counter = 0;
  int total_characters = 0;
  while( (c = getc(file)) != EOF) {
    total_characters ++;
    if(is_vowel(c)) {
      vowel_counter ++;
    }
  }
  
  printf("Total characters %d vowels: %d\n", total_characters, vowel_counter);
  return 0;
}
