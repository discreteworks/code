#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *next;
  int data;
} node;

int main() {
  node *n = (node*)malloc(sizeof(node));
  n->next = NULL;
  n->data = 1;
  printf("Node data:%d\n", n->data);
  free(n);
  return 0;
}
