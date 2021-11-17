#include "pq.h"
#include<stdio.h>

#include <stdlib.h>

//linklist node
struct pq {
  void *value;  
  double key;
  //ptr->next
  pq *next;
};


struct pq *head_n = NULL; //node head


/* Allocates and initializes a new pq */
pq* pq_create()
{
  return (pq*)malloc(sizeof(pq));
}


/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value)
{

   struct pq *temp=malloc(sizeof(pq));
   temp ->value=value;
   temp-> next =head_n;
   head =temp;


}
void insertionSort(pq* head)
    {
        // Initialize sorted linked list
        struct pq *sort= NULL;
        struct pq* current = head;
        // Traverse the given linked list and insert every
        // node to sorted
        while (current != NULL) {
            // Store next for next iteration
            struct pq* next = current->next;
            // insert current in sorted linked list
            
            if (sort == NULL || sort->value >= current->value) {
            current->next = sort;
            sort= current;
        }
        else {
            struct pq* newcurrent = sort;
            /* Locate the node before the point of insertion
             */
            while (newcurrent->next != NULL && newcurrent->next->value < current->value) {
                newcurrent = newcurrent->next;
            }
            current->next = newcurrent->next;
            newcurrent->next = current;
        }
            // Update current
            current = next;
        }
        // Update head_ref to point to sorted linked list
        head = sort;
    }

void* pq_pop(pq *head)
{
  struct pq *p = head_n->value;
  head_n = head_n->next;
  return p;
}

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */

void pq_destroy(pq *head)
{
  free(head);
}
