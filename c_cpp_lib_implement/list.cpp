#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* link;
};
typedef struct node node;

node *create(void)
{
  node *first;
  first = malloc(sizeof(node));
  first->data = 0;
  first->link = NULL;
  return first;
}

void insert(node *first, node x)
{
  node *temp;
  temp = malloc(sizeof(node));
  if (first) {
    temp->link = x.link;
    x.link = temp;
  }
  else {
    temp->link = NULL;
    first = temp;
  }
}

