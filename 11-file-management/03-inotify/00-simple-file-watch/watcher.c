#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

int main(int argc, char const *argv[]) {
  int infd;
  struct inotify_event event;

  if((infd = inotify_init()) == -1) {
    perror("inotify_init");
    exit(1);
  }

  int wfd = inotify_add_watch(infd, "./watchme.txt", IN_MODIFY);

  // block until file not modified
  if(read(infd, &event, sizeof(event)) == -1) {
    perror("read");
    close(infd);
    exit(1);
  }

  fprintf(stdout, "event occured on file: %d\n", event.len);

  close(infd);
  return 0;
}
