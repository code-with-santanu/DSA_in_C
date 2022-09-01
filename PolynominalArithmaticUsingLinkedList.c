#include <stdio.h>
#include <stdlib.h>

typedef struct polynominal
{
    int coef;
    int exp;
    struct polynominal *next;
} P_node;

/* =============== PROTOTYPE DECLERATION ===============*/
P_node *create_node(int, int);
void create_poly_func(P_node **);
void Insert_node(P_node **, P_node *);
void Print_func(P_node *);
P_node *poly_add(P_node *, P_node *);
P_node *poly_mult(P_node *, P_node *);

int main()
{
    P_node *poly1, *poly2, *head1, *head2;
    poly1 = poly2 = head1 = NULL;

    printf("\nEnter First Polynominal...");
    create_poly_func(&poly1);

    printf("\nEnter second polynominal...");
    create_poly_func(&poly2);

    Print_func(poly1);
    Print_func(poly2);

    printf("\nThe polynominal after addition...\n");
    head1 = poly_add(poly1, poly2);
    Print_func(head1);

    printf("\nThe polynominal after Multiplication...\n");
    head2 = poly_mult(poly1, poly2);
    Print_func(head2);

    return 0;
}

/* =============== FUNCTION  DEFINITIONS =============== */
P_node *create_node(int co, int ex)
{
    P_node *temp;
    temp = (P_node *)malloc(sizeof(P_node));
    temp->coef = co;
    temp->exp = ex;
    temp->next = NULL;

    return temp;
}

// Insertion in a sorted order
void Insert_node(P_node **poly, P_node *temp)
{
    P_node *cur = *poly;

    // Here the code is for descending order
    if (*poly == NULL || (*poly)->exp < temp->exp) // for first two nodes in order
    {
        temp->next = *poly; // Inserting the node at the beginning
        *poly = temp;
        return;
    }
    while (cur->next != NULL && cur->next->exp > temp->exp) // checking the exp of temp is less or not / sorting wrt exp
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
}

void create_poly_func(P_node **poly)
{
    int i, n, co, ex;
    P_node *temp = NULL;

    printf("\nEnter the no of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter the coefficient: ");
        scanf("%d", &co);

        printf("\nEnter the exponent: ");
        scanf("%d", &ex);

        temp = create_node(co, ex);
        Insert_node(poly, temp);
    }
    return;
}

void Print_func(P_node *cur)
{
    while (cur != NULL)
    {
        printf("(%dx^%d)", cur->coef, cur->exp);
        cur = cur->next;

        if (cur != NULL)
        {
            printf(" + ");
        }
        else
        {
            printf("\n");
        }
    }
}

P_node *poly_add(P_node *poly1, P_node *poly2)
{
    P_node *head3 = NULL, *temp;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp == poly2->exp)
        {
            temp = create_node((poly1->coef + poly2->coef), poly1->exp);
            Insert_node(&head3, temp);

            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exp > poly2->exp)
        {
            temp = create_node(poly1->coef, poly1->exp);
            Insert_node(&head3, temp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            temp = create_node(poly2->coef, poly2->exp);
            Insert_node(&head3, temp);
            poly2 = poly2->next;
        }
    }

    // If any one polynominal is reaches to the end and other's terms are remaining
    while (poly1 != NULL)
    {
        temp = create_node(poly1->coef, poly1->exp);
        Insert_node(&head3, temp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        temp = create_node(poly2->coef, poly2->exp);
        Insert_node(&head3, temp);
        poly2 = poly2->next;
    }

    return head3;
}

P_node *poly_mult(P_node *poly1, P_node *poly2)
{
    P_node *head = NULL, *temp = NULL, *ptr = poly2;

    if (poly1 == NULL || poly2 == NULL)
    {
        printf("\nNo Polynominal...");
    }
    else
    {
        while (poly1 != NULL)
        {
            while (ptr != NULL)
            {
                temp = create_node((poly1->coef * ptr->coef), (poly1->exp + ptr->exp)); // multiplying the coeff and adding the exponent
                Insert_node(&head, temp);
                ptr = ptr->next;
            }
            poly1 = poly1->next;
            ptr = poly2;
        }
    }

    // Adding all the nodes having same exponent
    ptr = head;
    temp = NULL;
    while (ptr->next != NULL)
    {
        if (ptr->exp == ptr->next->exp)
        {
            ptr->coef = ptr->coef + ptr->next->coef; // adding the coef of nodes having equal coef

            temp = ptr->next;
            ptr->next = ptr->next->next; // deleting the next node having same expo
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr = ptr->next;
        }
    }

    return head;
}