#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/***************************************************
 * Read & draw
 * 
 ***************************************************/

int line_number = 1;

int main(int argc, char const *argv[]) {
  FILE *file = fopen("./../resources/nile.csv", "r");


  if(!file) {
    perror("error");
    return EXIT_FAILURE;
  }

  // read header
  char header[256];
  fgets(header, 256, file);
  int year;
  double level;
  while (feof(file) == 0) {
    fscanf(file, "%d, %lf", &year, &level);

    fprintf(stdout, "%03d │", year);

    int lev = (level * 10) - 85;
    for (int i=0;i<lev;i++)
      fprintf(stdout, "▒");
    
    for (int i=0;i<55-lev;i++)
      fprintf(stdout, "█");
    fprintf(stdout, "│ %07.4f\n", level);
  }

  fclose(file);
  
  return 0;
}
