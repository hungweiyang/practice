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

    while (iterator && iterator->val < val) {
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

    while (*iterator && (*iterator)->val < val)
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

void traverse()
{   
    struct node *iterator = head;
  
    while (iterator)
    {
        printf("%d, ", iterator->val);
        iterator = iterator->next;
    } 

    printf("\n");
}

int main()
{
    void (*insert)(int) = &insert_v2;
    void (*remove)(int) = &remove_v1;

    insert(2);
    insert(100);
    insert(1);
    insert(5566);
    insert(33);

    traverse();

    remove(2);
    traverse();

    remove(1);
    traverse();  
}