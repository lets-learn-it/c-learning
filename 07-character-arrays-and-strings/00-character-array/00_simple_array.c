#include<stdio.h>
#include<string.h>

int main() {
  // name1 and name2 are equivalent
  char name1[] = "abc";
  char name2[] = {'a', 'b', 'c', '\0'};

  printf("strcmp(name1, name2): %d\n", strcmp(name1, name2));

  printf("name1: %s & length: %ld\n", name1, sizeof(name1));
  printf("name2: %s & length: %ld\n", name2, sizeof(name2));

  char* s = "Parikshit";
  printf("%s", s);
  return 0;
}
