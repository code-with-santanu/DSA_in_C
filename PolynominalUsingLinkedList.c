#include <stdio.h>
#include <stdlib.h>

typedef struct polynominal
{
    int co;
    int exp;
    struct polynominal *next;
} Poly;

/* =============== PROTOTYPE DECLERATION ===============*/
Poly *create_node(int, int);
void Insert_node(Poly **, Poly *);
void Print_func(Poly **);

int main()
{
    int co, exp, n, i;
    Poly *head = NULL, *temp = NULL;

    printf("\nEnter the no of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter the co-efficient: ");
        scanf("%d", &co);

        printf("\nEnter the exponent: ");
        scanf("%d", &exp);

        temp = create_node(co, exp);
        Insert_node(&head, temp);
    }
    Print_func(&head);

    return 0;
}

/* =============== FUNCTION  DEFINITIONS =============== */
Poly *create_node(int co, int exp)
{
    Poly *temp = NULL;
    temp = (Poly *)malloc(sizeof(Poly));
    temp->co = co;
    temp->exp = exp;
    temp->next = NULL;

    return temp;
}

// Inserting the each term to the list
void Insert_node(Poly **head, Poly *temp)
{
    Poly *cur = *head;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

void Print_func(Poly **head)
{
    Poly *cur = *head;

    while (cur != NULL)
    {
        printf("(%dx^%d)", cur->co, cur->exp);
        cur = cur->next;

        if (cur != NULL)
        {
            printf(" + ");
        }
    }
}