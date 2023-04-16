#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dfa.h"

void initState(State *state, char *name, int isFinal) {
  state->isFinal = isFinal;
  state->name = name;
  state->totalTransitions = 0;
}

void addTransition(State *from, State *to, char key) {
  Pair p = {key, to};
  from->transition[from->totalTransitions++] = p;
}

int runMachine(State *start, const char *input) {
  State *state = start;
  int flag = 0;
  while (1) {
    printf("State: %5s (%d), Input: %c\n", state->name, state->isFinal, *input);
    if (*input == '\0' && !state->isFinal) return 0;
    if (*input == '\0' && state->isFinal) return 1;

    flag = 0;

    for (int i=0;i<state->totalTransitions;i++) {
      if (*input == state->transition[i].key) {
        flag = 1;
        state = state->transition[i].state;
        break;
      }
    }
    if (!flag) {
      printf("Transition for input '%c' from state '%s' not found.\n", *input, state->name);
      return 0;
    }
    input += 1;
  }
  
}
