#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <seccomp.h>

int main(int argc, char const *argv[]) {
  scmp_filter_ctx seccomp_ctx;
	uint32_t seccomp_default_action = SCMP_ACT_KILL_PROCESS;

  seccomp_ctx = seccomp_init(seccomp_default_action);

  if (NULL == seccomp_ctx) {
		fputs("failed to init seccomp context\n", stderr);
		exit(1);
	}

  // add syscall to allow (all other will be denied)
  if (seccomp_rule_add_exact(seccomp_ctx, SCMP_ACT_ALLOW, __NR_open, 0)) {
		seccomp_release(seccomp_ctx);
		exit(1);
	}

  seccomp_load(seccomp_ctx);

  // This will fail //
  printf("Hellow WOrld");

  seccomp_release(seccomp_ctx);
  return 0;
}
