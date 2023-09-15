#include <stdio.h>
#include <stdlib.h>

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

struct Node * Search(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
        {
            return p;
        } else {
            p = p->next;
        }
    }
    return NULL;
}

struct Node * SearchRecursion(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return SearchRecursion(p->next, key);
}

// This is move to head implementation to improve linear searching.
struct Node * SearchImproved(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p != NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }


}

int main()
{
    int A[] = {3,5,7,10,15};

    Create(A,5);

    printf("Search: %d \n", Search(first, 11));

    printf("Search (Regression): %d \n", Search(first, 7));

    return 0;
}