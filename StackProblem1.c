/* Create a stack using array of 10 elements .Delete an element at the 4th position
   from the buttom using push() and pop() */

#include <stdio.h>
#include <stdlib.h>

/* ======== GLOBAL  DECLARATION ======== */
int *stk, top = -1, size;

/* =============== PROTOTYPE DECLERATION ===============*/

void create_stk();
void Push(int);
int Pop();
void Display();

int main()
{
    int i, n, arr[6];

    create_stk();

    for (i = 1; i <= 10; i++)
    {
        printf("\nEnter the value: ");
        scanf("%d", &n);
        Push(n);
    }

    for (i = 0; i < 6; i++)
    {
        n = Pop();
        arr[i] = n;
    }
    Pop();

    for (i = 5; i >= 0; i--)
    {
        Push(arr[i]);
    }

    Display();
    return 0;
}

/* =============== FUNCTION  DEFINITIONS =============== */

void create_stk()
{
    printf("\nEnter the maximum size of the stack: ");
    scanf("%d", &size);
    stk = (int *)malloc(size * sizeof(int));
}

void Display()
{
    int *p = stk, i;

    for (i = 0; i <= top; i++)
    {
        printf("%d\t", *(p++));
    }
}

void Push(int n)
{
    if (top == size - 1)
    {
        printf("\nSTACK OVERFLOW!!!");
    }
    else
    {
        stk[++top] = n; /* pushing the value using indexing method */
    }
}

int Pop()
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW!!!");
    }
    return stk[top--];
}