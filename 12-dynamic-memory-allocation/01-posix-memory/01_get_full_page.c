#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    /* for getpagesize() */
#include <sys/mman.h>  /* for mmap() */
#include <string.h>

static size_t SYSTEM_PAGE_SIZE = 0;

void mm_init() {
  SYSTEM_PAGE_SIZE = getpagesize();
}

/* 
 * requesting units number of contiguous pages from kernel
 * returns starting address
 */
static void * mm_get_new_vm_page_from_kernel(int units) {
  char *vm_page = mmap(NULL, units * SYSTEM_PAGE_SIZE, /* size memory */
                    PROT_READ | PROT_WRITE | PROT_EXEC,
                    MAP_PRIVATE | MAP_ANON, 0, 0);
  
  if (vm_page == MAP_FAILED) {
    perror("mmap");
    printf("ERROR: VM page allocation failed.\n");
    return NULL;
  }

  /* initialize memory to 0 */
  memset(vm_page, 9, units * SYSTEM_PAGE_SIZE);
  return (void *) vm_page;
}

/* 
 * returns units number of contiguous pages to kernel
 * start is pointed by vm_page
 */
static void mm_return_vm_page_to_kernel(void *vm_page, int units) {
  if (munmap(vm_page, units * SYSTEM_PAGE_SIZE)) {
    printf("ERROR: Could not munmap VM page to kernel.\n");
  }
}


int main() {
  mm_init();

  printf("VM page size: %lu\n", SYSTEM_PAGE_SIZE);

  char *p1 = (char *) mm_get_new_vm_page_from_kernel(1);

  printf("Got page with start address: %p\n", p1);

  char *s = "Hi, I am Parikshit from India.";

  /* It will use only strlen(s) part of page. Remaining whole page will be empty. */
  strncpy(p1, s, strlen(s));
  printf("String from allocated page: %s", p1);

  mm_return_vm_page_to_kernel(p1, 1);

  return 0;
}
