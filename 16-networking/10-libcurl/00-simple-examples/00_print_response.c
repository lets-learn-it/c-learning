#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  CURL *curl = curl_easy_init();

  if (!curl) {
    fprintf(stderr, "init failed...\n");
    exit(EXIT_FAILURE);
  }

  // set options
  curl_easy_setopt(curl, CURLOPT_URL, "https://avabodha.in");

  // perform request
  CURLcode result = curl_easy_perform(curl);

  if (result != CURLE_OK) {
    fprintf(stderr, "ERROR: %s\n", curl_easy_strerror(result));
  }
  curl_easy_cleanup(curl);
  return 0;
}
