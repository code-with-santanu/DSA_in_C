/* Write a program to add 2 numbers using Linked List */

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
} List;

List *create_node(int);
void create_list(List **, int);
void Reverse_list(List **);
List *AddNo(List *, List *);
void Display(List *);

int main()
{
    int a, b;
    List *L1, *L2, *R;
    L1 = L2 = R = NULL;
    printf("\nEnter two numbers: ");
    scanf("%d\t%d", &a, &b);

    create_list(&L1, a);
    create_list(&L2, b);

    printf("\nFirst no is : ");
    Display(L1);
    printf("\nSecond no is : ");
    Display(L2);

    Reverse_list(&L1);
    Reverse_list(&L2);

    R = AddNo(L1, L2);
    printf("\nThe result= ");
    Display(R);

    return 0;
}

List *create_node(int n)
{
    List *temp;
    temp = (List *)malloc(sizeof(List));

    temp->value = n;
    temp->next = NULL;

    return temp;
}

void create_list(List **head, int n)
{
    List *temp = NULL;
    do
    {
        temp = create_node(n % 10);
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            temp->next = *head;
            *head = temp;
        }
        n /= 10;
    } while (n != 0);
}

void Reverse_list(List **head)
{
    List *current, *prev, *sprev;
    current = *head;
    prev = sprev = NULL;

    while (current != NULL)
    {
        sprev = prev;
        prev = current;
        current = current->next;
        prev->next = sprev;
    }
    *head = prev;
}

List *AddNo(List *head1, List *head2)
{
    List *head3 = NULL, *temp = NULL;
    int sum, carry = 0;

    while (head1 || head2)
    {
        sum = 0;
        if (head1)
        {
            sum += head1->value;
        }
        if (head2)
        {
            sum += head2->value;
        }
        sum += carry;
        carry = sum / 10;
        create_list(&head3, sum % 10);

        if (head1)
        {
            head1 = head1->next;
        }
        if (head2)
        {
            head2 = head2->next;
        }
    }
    if (carry > 0)
    {
        create_list(&head3, carry);
    }

    return head3;
}

void Display(List *head)
{
    while (head)
    {
        printf("%d", head->value);
        head = head->next;
    }
}