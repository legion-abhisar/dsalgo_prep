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

    for(i = 1; i < n; i++)
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

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if(index < 1 || index > Count(p))
        return -1;

    if(index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);    // free() is used to deallocate
        return x;
    } else {
        p = first;
        q = NULL;

        for(i=0; i<index-1; i++ ){
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    Create(A,5);

    Display(first);
    printf("\n\n");

    Delete(first, 4);

    Display(first);
    printf("\n\n");

    return 0;
}