#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for(i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x)
{
    if(st->top == st->size-1)
        printf("Stack overflow.\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack underflow.\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top - index + 1 < 0)
        printf("Invalid Index.\n");
    x = st.S[st.top - index + 1];

    return x;
}

int IsEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int IsFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack st)
{
    if(IsEmpty(st))
        return -1;
    else
        return st.S[st.top];
}

int main()
{
    struct Stack st;
    Create(&st);

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    
    Display(st);

    printf("Number peeked: %d \n", Peek(st, 3));

    Display(st);

    return 0;
}