#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>

void hash_it(unsigned char *data, unsigned char *digest) {
  SHA_CTX ctx;

  SHA1_Init(&ctx);

  int len = strlen(data);

  SHA1_Update(&ctx, data, len);

  SHA1_Final(digest, &ctx);
}

int main(int argc, char const *argv[]) {
  unsigned char s[] = "This is demo string!!!";
  unsigned char digest[SHA_DIGEST_LENGTH];

  hash_it(s, digest);

  for (int i=0;i<SHA_DIGEST_LENGTH;i++)
  /* 
   * print as an unsigned hexadecimal integer, 
   * with two digits and leading zeros if necessary. 
  */
    printf("%02x", digest[i]);
  
  printf("\n");

  return 0;
}
