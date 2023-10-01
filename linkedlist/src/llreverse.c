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

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
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

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int)*Count(p));

    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    while(q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

int main()
{
    int A[] = {10,20,30,40,50, 20};
    Create(A, 6);

    /*
    Reverse1(first);

    printf("LinkedList after Reverse1:");
    Display(first);
    printf("\n\n");
    */

    /*
    Reverse2(first);

    printf("LinkedList after Reverse2: ");
    Display(first);
    printf("\n\n");
    */

    Reverse3(NULL, first);

    printf("LinkedList after Reverse3: ");
    Display(first);
    printf("\n\n");

    return 0;
}