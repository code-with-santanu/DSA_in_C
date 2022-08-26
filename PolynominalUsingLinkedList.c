#include <stdio.h>
#include <stdlib.h>

typedef struct polynominal
{
    int coef;
    int exp;
    struct polynominal *next;
} P_node;

P_node *poly;

P_node *create_node(int, int);
void create_poly_func();
void Insert_node();
void Print_func();

int main()
{
    create_poly_func();
    Print_func();

    return 0;
}

P_node *create_node(int co, int ex)
{
    P_node *temp;
    temp = (P_node *)malloc(sizeof(P_node));
    temp->coef = co;
    temp->exp = ex;
    temp->next = NULL;

    return temp;
}

void Insert_node()
{
    P_node *temp = NULL, *cur = poly;
    int co, ex;

    printf("\nEnter the coefficient: ");
    scanf("%d", &co);

    printf("\nEnter the exponent: ");
    scanf("%d", &ex);

    temp = create_node(co, ex);
    if (poly == NULL)
    {
        poly = temp;
        return;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

void create_poly_func()
{
    int i, n;

    printf("\nEnter the no of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        Insert_node();
    }
    return;
}

void Print_func()
{
    P_node *cur = poly;

    while (cur != NULL)
    {
        printf("(%dx^%d)", cur->coef, cur->exp);
        cur = cur->next;

        if (cur != NULL)
        {
            printf(" + ");
        }
    }
}