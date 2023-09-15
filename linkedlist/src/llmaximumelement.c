#include <stdio.h>
#include <stdlib.h>

#define MIN_INT -32768

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

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

int Max(struct Node *p)
{
    int m = MIN_INT;
    while(p)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int MaxRecursion(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return MIN_INT;
    else
    {
        x = MaxRecursion(p->next);
        return x > p->data ? x : p->data;
    }
}

int main()
{
    int A[] = {3,5,7,10,15};

    Create(A, 5);

    printf("Max element: %d \n", Max(first));

    printf("Max element (Recursion): %d \n", MaxRecursion(first));

    return 0;
}