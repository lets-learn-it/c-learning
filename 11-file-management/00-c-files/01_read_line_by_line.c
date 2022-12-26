#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/***************************************************
 * Give Line Numbers & underline search string
 * ./a.out  ./resources/shivaji.txt Shivaji
 ***************************************************/

int line_number = 1;

int main(int argc, char const *argv[]) {
  if(argc < 3) {
    fprintf(stderr, "Filename not provided...\n");
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");
  char search[256];
  strncpy(search, argv[2], 256);

  char buffer[BUFFER_SIZE];
  char *pch;
  char *point;

  if(!file) {
    perror("error");
    return EXIT_FAILURE;
  }

  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    pch = strstr (buffer, search);

    if (pch != NULL) {
      fprintf(stdout, "%03d | ", line_number);
      point = buffer;
      while (pch) {
        fprintf(stdout, "%.*s\033[4m%.*s\033[24m", (int) (pch - point), point, (int) strlen(search), pch);
        point = pch + strlen(search);
        pch = strstr (point, search);
      }
      fprintf(stdout, "%s", point);
    
    } else {
      fprintf(stdout, "%03d | %s", line_number, buffer);
    }
    line_number ++;
  }

  fclose(file);
  
  return 0;
}
