#include <stdio.h>
#include <stdlib.h>

struct node
{
   int val;
   struct node *next;
} *head;

void insert_v1(int val)
{
    struct node *iterator = head;
    struct node *prev = head;
    struct node *n = (struct node *)malloc(sizeof(struct node));

    while (iterator) {
        prev = iterator;
        iterator = iterator->next;
    }

    if (iterator == head)
        head = n;
    else
        prev->next = n;

    n->next = iterator;
    n->val = val;

    return;
}

void insert_v2(int val)
{
    struct node **iterator = &head;
    struct node *n = (struct node *)malloc(sizeof(struct node));

    while (*iterator)
        iterator = &(*iterator)->next;

    struct node *tmp;
    tmp = *iterator;
    *iterator = n;

    n->next = tmp;
    n->val = val;

    return;
}

void remove_v1(int val)
{
    struct node *iterator = head;
    struct node *prev = head;

    while (iterator && iterator->val != val) {
        prev = iterator;
        iterator = iterator->next;
    }

    if (iterator == head)
        head = head->next;
    else
        prev->next = prev->next->next;

    return;  
}

void remove_v2(int val)
{
    struct node **iterator = &head;

    while (*iterator && (*iterator)->val != val)
        iterator = &((*iterator)->next);

    *iterator = (*iterator)->next;

    return;  
}

void traverse(struct node* n)
{   
    struct node *iterator = n;
  
    while (iterator)
    {
        printf("%d, ", iterator->val);
        iterator = iterator->next;
    } 

    printf("\n");
}

void bubblesort()
{
    struct node *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i; j != NULL; j = j->next) {
            if (i->val > j->val)
            {
                int t = i->val;
                i->val = j->val;
                j->val = t;
            }
        }
    }
}

void mergesort(struct node **ret)
{
    struct node *i, *j, *k;
    struct node *n = *ret;
  
    if (n == NULL || n->next == NULL)
        return;

    for (i = n, j = n; j != NULL;) {
        j = j->next;
        if (j) {
            k = i;
            i = i->next;
            j = j->next;
        }
    }
    
    k->next = NULL;

    mergesort(&n);
    mergesort(&i);
  
    j = NULL;
    for(; n && i ;) {
        if (n->val < i->val) {
            if (j == NULL) {
                j = n;
                *ret = j;
            } else {
                j->next = n;
                j = j->next;
            }
            n = n->next;
        } else {
            if (j == NULL) {
                j = i;
                *ret = j;
            } else {
                j->next = i;
                j = j->next;
            }
            i = i->next;
        }
    }
    
    if (n) {
        j->next = n;
        j = j->next;
        n = n->next;
    } else {
        j->next = i;
        j = j->next;
        i = i->next;
    }

    j = NULL;
}

int main()
{
    void (*insert)(int) = &insert_v2;
    void (*remove)(int) = &remove_v1;

    insert(100);  
    insert(2);
    insert(1);
    insert(5566);
    insert(33);
    insert(789);

    traverse(head);


    mergesort(&head);
    traverse(head);

    // remove(2);
    // traverse();

    // remove(1);
    // traverse();  
}