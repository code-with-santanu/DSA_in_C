/* Convert  Decimal no to Binary using stack */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_using_list
{
    int value;
    struct stack_using_list *next;
} Stk;

Stk *s_top = NULL;

/* =============== PROTOTYPE DECLERATION ===============*/

Stk *create_node(int);
void Push(int);
int Pop();
void Display();
void BinToDec(Stk **, int);

int main()
{
    int d;

    printf("\nEnter the decimal no: ");
    scanf("%d", &d);

    BinToDec(&s_top, d);
    printf("\nThe equivalent binary no of the decimal no is: ");
    Display(s_top);

    return 0;
}

Stk *create_node(int n)
{
    Stk *temp;
    temp = (Stk *)malloc(sizeof(Stk));

    temp->next == NULL;
    temp->value = n;

    return temp;
}

void Push(int n)
{
    Stk *temp;
    temp = create_node(n);

    temp->next = s_top;
    s_top = temp;
}

int Pop()
{
    Stk *temp;
    int n;
    temp = s_top;
    s_top = s_top->next;

    n = temp->value;
    free(temp);

    return n;
}

void BinToDec(Stk **top, int d)
{
    int r;
    while (d != 0)
    {
        Push(d % 2);
        d /= 2;
    }
}

void Display()
{
    Stk *c = s_top;
    while (c != NULL)
    {
        printf("%d", c->value);
        c = c->next;
    }
}