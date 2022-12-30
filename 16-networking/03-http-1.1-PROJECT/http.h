
#ifndef __HTTP_H__
#define __HTTP_H__

#define MAX_HEADERS 20

typedef struct {
  char name[30], value[50];
} header_t;

typedef struct http_request_ {
  char method[10];
  char path[20];
  char version[10];
  header_t headers[MAX_HEADERS];
  char data[1024];
} http_request;

/* for response */
char * set_first_line(int status_code, char *status_string);
char * set_headers(header_t *headers);
int send_response(int fd, http_request *req);

/* for request */
http_request * parse_http_request(char *req);
char * to_string(http_request *req);

#endif