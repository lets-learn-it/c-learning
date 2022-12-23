
#ifndef _GLDLL_H_
#define _GLDLL_H_

typedef struct gldll_node_ {
  /* There is no data member in node */
  struct gldll_node_ *left;
  struct gldll_node_ *right;
} gldll_node_t;

typedef struct gldll_ {
  gldll_node_t *head;

  int (*key_match) (void *, void *);
  int (*comparison_fn) (void *, void *);

  /* This is extra */
  unsigned int offset;
} gldll_t;

void gldll_add(gldll_t *lst, gldll_node_t *node);
void print(gldll_t *lst, void (*fn) (gldll_node_t *node));


#endif

