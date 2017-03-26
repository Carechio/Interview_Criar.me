#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node{
  double item;
  link next;
};

link newNode(double item);
void freeList(link head);
void insertNext(link cur, link t);
link removeNext(link t);
void printList(link head);

int main(int argc, char const *argv[]) {
  if(argc < 2) return 0;
  link cur, head = newNode(atof(argv[1]));
  for(int i = argc; i > 2; i--){
    cur = newNode(atof(argv[i - 1]));
    insertNext(head, cur);
  }
  printList(head);
  return 0;
}

//receieves value as parameter
//returns pointer to a new node
link newNode(double item){
  link t = malloc(sizeof *t);
  if(t == NULL) return NULL;
  t->next = NULL;
  t->item = item;
  return t;
}

//receieves pointer to a list as parameter
//frees the memory occupied by the list
void freeList(link head){
  link cur;
  while(head->next){
    cur = head->next;
    free(head);
    head = cur;
  }
  return;
}

//receieves two node pointers as parameter
//insert the second node after the first one
void insertNext(link cur, link t){
  t->next = cur->next;
  cur->next = t;
  return;
}

//receieves pointer to a node as parameter
//removes the node from the list and returns the node pointer
link removeNext(link t){
  link rmv = t->next;
  t->next = t->next->next;
  return rmv;
}

//receieves pointer to a list as parameter
//prints the list in the STDOUT
void printList(link head){
  link cur;
  printf("\n The linked list: ");
  for(cur = head; cur->next; cur = cur->next){
    printf("%f -> ", cur->item);
  }
  printf("%f -> NULL\n", cur->item);
  return;
}
