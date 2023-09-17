#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
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

int add(struct Node *p)
{
    int sum = 0;
    while(p != NULL)
    {
        sum += p->data;
        printf("%d ", sum);
        p = p->next;
    }
    return sum;
}

int addRecursion(struct Node *p)
{
    if(p == 0)
        return 0;
    else
        return addRecursion(p->next) + p->data;
}

int main()
{
    int A[] = {3,5,7,10,15,8,12,20};

    create(A, 8);

    printf("Sum : %d ", add(first));
    printf("\n");
    printf("Recursion: Sum : %d ", addRecursion(first));

    return 0;
}










