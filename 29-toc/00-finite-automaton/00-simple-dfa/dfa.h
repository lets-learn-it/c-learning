
typedef struct _state State;  /* forward declaration */

typedef struct _pair {
  char key;
  State *state;
} Pair;


struct _state {
  char *name;
  int isFinal;               /* is this state final */
  int totalTransitions;      /* number of transitions from this state */
  Pair transition[10];
};

void initState(State *state, char *name, int isFinal);
void addTransition(State *from, State *to, char key);
int runMachine(State *start, const char *input);
