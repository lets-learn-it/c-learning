#include "http.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/uio.h>

/* for response */
char * set_first_line(int status_code, char *status_string) {
  char *buffer = malloc(sizeof(char)*30);
  sprintf(buffer, "HTTP/1.1 %d %s\r\n", status_code, status_string);
  return buffer;
}

char * set_headers(header_t *headers) {
  char *data = malloc(sizeof(char) * 1024);

  int i = 0;
  while(*(headers)[i].name != '\0' && i < MAX_HEADERS) {
    sprintf(data + strlen(data), "%s: %s\r\n", &(*(headers)[i].name), &(*(headers)[i].value)); 
    i++;
  }

  strcat(data, "\r\n");
  return data;
}

int send_response(int fd, http_request *req) {
  int nbytes = 0;
  char *first_line = set_first_line(200, "OK");
  header_t *header = (header_t *) malloc(sizeof(header_t)*20);

  char *data = to_string(req);

  strcpy(header[0].name, "Content-Type"); strcpy(header[0].value, "application/json");
  strcpy(header[1].name, "Content-Length"); sprintf(header[1].value, "%ld", strlen(data));
  strcpy(header[2].name, "Server"); strcpy(header[2].value, "PSKP");
  char *headers = set_headers(header);

  struct iovec res[3];

  res[0].iov_base = first_line;
  res[0].iov_len = strlen(first_line);
  
  res[1].iov_base = headers;
  res[1].iov_len = strlen(headers);

  res[2].iov_base = data;
  res[2].iov_len = strlen(data);

  fprintf(stdout, "%s %s %d %s\n", req->method, req->path, 200, "OK");

  nbytes = writev(fd, res, 3);

  if (nbytes < 0) {
    perror("writev");
  }
  return nbytes;
}

/* for request */
http_request * parse_http_request(char *req) {
  http_request *request = malloc(sizeof(http_request));

  // get body if any
  char *body = strstr(req, "\r\n\r\n");
  // add terminating char so that when we parse headers we should not consider body
  *body = '\0';
  // get actual body, leave \r\n\r\n
  body = body + 4;
  strcpy(request->data, body);

  // get first line which has method, path, http version
  char *first_line = strtok(req, "\r\n");
  sscanf(first_line, "%s %s %s", request->method, request->path, request->version);
  
  char *header;
  int i = 0;
  while ((header = strtok(NULL, "\r\n")) && strchr(header, ':') && i < MAX_HEADERS) {
    // split each header into key & value

    sscanf(header, "%[^:]: %[^\r]", &(*(request->headers)[i].name), &(*(request->headers)[i].value));
    i++;
  }
  *(request->headers)[i].name = '\0'; // end of headers

  return request;
}

char * to_string(http_request *req) {
  char *data = malloc(sizeof(char) * 1024);

  sprintf(data, "{\"Method\": \"%s\",\"Path\": \"%s\",\"Version\": \"%s\",\n", req->method, req->path, req->version);
  strcat(data, "\"headers\": [");
  int i = 0;
  while(*(req->headers)[i].name != '\0' && i < MAX_HEADERS) {
    sprintf(data + strlen(data), "{\"Name\": \"%s\",\"Value\": \"%s\"},", &(*(req->headers)[i].name), &(*(req->headers)[i].value)); 
    i++;
  }
  *(data + strlen(data) - 1) = '\0';
  strcat(data, "]}");
  return data;
}