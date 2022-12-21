#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>

typedef struct {
  char name[30], value[50];
} header_t;

typedef struct http_request_ {
  char method[10];
  char path[20];
  char version[10];
  header_t headers[20];
  char data[1024];
} http_request;

void print(http_request *req, char *res) {
  char temp[100];
  
  sprintf(temp, "Method: %s  Path: %s  Version: %s\n", req->method, req->path, req->version);
  strcpy(res, temp);

  int i=0;
  while(*(req->headers)[i].name != '\0') {
    sprintf(temp, "Name: %s\tValue: %s\n", &(*(req->headers)[i].name), &(*(req->headers)[i].value)); 
    i++;
    strcat(res, temp);
  }
  sprintf(temp, "data: %s\n", req->data);
  strcat(res, temp);

  int nbytes = strlen(res);

  sprintf(temp, "HTTP/1.1 200 OK\r\nServer: PSKP\r\nContent-Type: text/html\r\nContent-Length: %d", nbytes);
  strcat(temp, "\r\n\r\n");
  
  // move whole res to right so that temp can fit at start
  // temp has HTTP related info ie. headers status etc
  memmove(res + strlen(temp), res, 1024-strlen(temp));
  
  // copy length of temp in freed space
  strncpy(res, temp, strlen(temp)-1); // do not include \0
}

void parse_http_request(char *req, char *res) {
  http_request *request = malloc(sizeof(http_request));

  // get body if any
  char *body = strstr(req, "\r\n\r\n");

  // add terminating char so that when we parse headers we should not consider body
  *body = '\0';

  // get actual body leave \r\n\r\n
  body = body + 4;

  strcpy(request->data, body);

  // get first line which has method, path, http version
  char *first_line = strtok(req, "\r\n");
  char *path = strstr(first_line, " ");
  *path = '\0';
  path += 1;
  char *version = strstr(path, " ");
  *version = '\0';
  version += 1;
  strcpy(request->method, first_line);
  strcpy(request->path, path);
  strcpy(request->version, version);
  
  char *header;
  int i = 0;
  while ((header = strtok(NULL, "\r\n")) != NULL) {
    // split each header into key & value
    char *value = strstr(header, ": ");
    *value = '\0';
    value += 2;
    char *key = header;
    strcpy(&(*(request->headers)[i].name), key);
    strcpy(&(*(request->headers)[i].value), value);
    i++;
  }
  *(request->headers)[i].name = '\0'; // end of headers
  print(request, res);
}

int main(int argc, char const *argv[]) {
  int sockfd, connfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serv_addr;
  int addrlen = sizeof serv_addr;
  char inbuffer[1024] = {0};
  char outBuffer[2048] = {0};

  if(sockfd <= 0) {
    perror("error while creating socket...");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8081);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // https://stackoverflow.com/questions/2208581/socket-listen-doesnt-unbind-in-c-under-linux
  int opt = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void *) &opt, sizeof(opt));

  if(bind(sockfd, (struct sockaddr *) &serv_addr, addrlen) < 0) {
    perror("bind failed...");
    exit(1);
  } 

  if(listen(sockfd, 3) < 0) {
    perror("Listen failed ...");
    exit(1);
  }

  if((connfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &addrlen)) < 0) {
    perror("accept error...");
    exit(1);
  }

  while(1) {
    memset(inbuffer, 0, 1024);
    memset(outBuffer, 0, 1024);

    // read returns 0 if connection closed normally
    // and -1 if error
    if(read(connfd, inbuffer, 1024) <= 0) {
      fprintf(stderr, "%s (code: %d)\n", strerror(errno), errno);
      fprintf(stderr, "Host disconnected\n");
      close(connfd);
      exit(0);
    }
    parse_http_request(inbuffer, outBuffer);
    fprintf(stderr, "%s", outBuffer);
    write(connfd, outBuffer, strlen(outBuffer));
  }

  return 0;
}
