#include <stdio.h>
#include "Item.h"
typedef struct node *link;

struct node {
  Item item;
  listNode next;
} 




link merge(link a, link b) {
  struct node head;
  link c = &head;

  while((a!=NULL) && (b != NULL)) {
    if(a->item < b->item) 
      {c->next = a; c = a;a = a->next;}
    else 
      {c->next = b; c = b; b = b->next;}
    c->next = (a==NULL) ? b:a;
    return head.next;
}

link mergeSort(link c) {
    link a; link b;
    // if c is null, or c.next is null, end of list has been reached
    if((c==NULL) || (c->next == NULL)) return c;
    a=c;b=c->next;
    while((b!=NULL) && (b->next!=NULL)
      {c = c->next; b = b->next->next;} // tortoise and hare pointers to find middle and end
    b = c->next; 
    return merge(mergeSort(a), mergeSort(b));

  }
}
