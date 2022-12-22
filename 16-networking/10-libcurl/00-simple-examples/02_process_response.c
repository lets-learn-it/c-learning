#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num = 0;

size_t got_data(char *buffer, size_t itemsize, size_t nitems, char *my_buffer) {
  int nbytes = itemsize * nitems;
  memcpy(my_buffer, buffer, nbytes);

  // add \0 at end
  *(my_buffer + nbytes) = '\0';

  char *current = my_buffer;
  char find[] = "Parikshit";

  while ((current = strstr(current, find)) != NULL) {
    num++;
    current += strlen(find);
  }
  
  return nbytes;
}

int main(int argc, char const *argv[]) {
  CURL *curl = curl_easy_init();
  char buffer[CURL_MAX_WRITE_SIZE];

  if (!curl) {
    fprintf(stderr, "init failed...\n");
    exit(EXIT_FAILURE);
  }

  // set options
  curl_easy_setopt(curl, CURLOPT_URL, "https://avabodha.in");

  // pass our buffer
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

  // whenever data comes call this function
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);

  // perform request
  CURLcode result = curl_easy_perform(curl);

  if (result != CURLE_OK) {
    fprintf(stderr, "ERROR: %s\n", curl_easy_strerror(result));
  }

  fprintf(stderr, "num: %d\n", num);

  curl_easy_cleanup(curl);
  return 0;
}
