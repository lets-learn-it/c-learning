#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>

#define BUFFER_SIZE 1024

void hash_it(FILE *file, unsigned char *digest) {
  unsigned char buffer[BUFFER_SIZE];
  SHA_CTX ctx;
  int nbytes;

  SHA1_Init(&ctx);

  while((nbytes = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
    SHA1_Update(&ctx, buffer, nbytes);

  SHA1_Final(digest, &ctx);
}

int main(int argc, char const *argv[]) {
  unsigned char filename[] = "राष्ट्रीय-प्रतिज्ञा.txt";
  unsigned char digest[SHA_DIGEST_LENGTH];

  FILE *file;

  if ((file = fopen(filename,"r")) == NULL) return EXIT_FAILURE;

  hash_it(file, digest);

  for (int i=0;i<SHA_DIGEST_LENGTH;i++)
  /* 
   * print as an unsigned hexadecimal integer, 
   * with two digits and leading zeros if necessary. 
  */
    printf("%02x", digest[i]);
  
  printf("\n");

  return 0;
}
