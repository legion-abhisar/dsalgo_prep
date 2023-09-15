#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

// Function to create linked list
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 0; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Count(struct Node *p)
{
    int c = 0;
    while (p != 0)
    {
        p = p->next;
        c++;
    }
    return c;
}

int CountRecursive(struct Node *p)
{
    if(p == 0)
        return 0;
    else
        return CountRecursive(p->next) + 1;
}

int CountRecursiveVariable(struct Node *p)
{
    int x = 0;
    if(p)
    {
        x = CountRecursiveVariable(p->next);
        return x + 1;
    }
}

int main()
{
    int A[] = {3,5,7,10,15};

    Create(A, 5);

    printf("No. of nodes: %d ", Count(first));
    printf("\n");
    printf("Recursive: No. of nodes: %d ", CountRecursive(first));
    printf("\n");
    printf("Recursive: No. of nodes: %d ", CountRecursiveVariable(first));

    return 0;
}