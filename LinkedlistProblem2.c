/*Write a program to find the max and min value from the list */

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
} List;

typedef struct MinMax
{
    int min;
    int max;
} M;

List *create_node(int);
void create_list(List **);
void Display(List *);
M MinMax(List *);

int main()
{
    List *head = NULL;
    M m;
    printf("\nCreate a list...");
    create_list(&head);
    Display(head);

    m = MinMax(head);

    printf("\nThe maximum and the minimum value of the list are: %d and %d", m.max, m.min);

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

void create_list(List **head)
{
    int n, no;
    List *temp = NULL, *cur = NULL;

    printf("\nHow many no want to add: ");
    scanf("%d", &n);

    while (n != 0)
    {
        printf("\nEnter the value: ");
        scanf("%d", &no);
        temp = create_node(no);

        if (*head == NULL)
        {
            *head = cur = temp;
        }
        cur->next = temp;
        cur = temp;
        n--;
    }
}

void Display(List *head)
{
    while (head)
    {
        printf("%d\t", head->value);
        head = head->next;
    }
}

M MinMax(List *head)
{
    M m;
    List *cur = head->next;

    m.min = head->value;
    while (cur != NULL)
    {
        if (cur->value < m.min)
        {
            m.min = cur->value;
        }
        cur = cur->next;
    }

    cur = head->next;
    m.max = head->value;
    while (cur != NULL)
    {
        if (cur->value > m.max)
        {
            m.max = cur->value;
        }
        cur = cur->next;
    }

    return m;
}