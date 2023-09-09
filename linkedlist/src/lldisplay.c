#include <stdio.h>
#include <stdlib.h>

// Declaration
// void Create(int A[], int n);
// void Display(struct Node *p);

struct Node
{
    int data;               // To store data of the node.
    struct Node *next;      // To store pointer to the next node.
}*first = NULL;

// Function to create linked list.
void Create(int A[], int n)
{
    int i;                      // Variable to loop through the array.
    struct Node *t, *last;      // Pointers to store references of node.
    first = (struct Node *)malloc(sizeof(struct Node)); // Creating head node.
    first->data = A[0];         // Assigning data to the head node.
    first->next = NULL;         // Assigning next node pointer to the head node.
    last = first;               // last points to the first node.

    for(i = 1; i < n; i++)      // For loop to iterate through array and create nodes.
    {
        t = (struct Node *)malloc(sizeof(struct Node)); // Creating node.
        t->data = A[i];         // Assigning data to the node.
        t->next = NULL;         // Assigning next pointer to the node.
        last->next = t;         // Here last node points to t (new node).
        last = t;               // Last becomes the t node.
    } 
}

// Function to display linked list.
void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    int A[] = {3,5,7,10,15};

    Create(A, 5);

    Display(first);

    return 0;
}