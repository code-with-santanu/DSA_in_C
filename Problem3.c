/*Write a program to insert value in both sorted in (increasing and decreasing) ordered linked list  */

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
} List;

List *create_node(int);
void Display(List *);
void IncreasingSortedInsert(List **, int);
void DecreasingSortedInsert(List **, int);

int main()
{
    int n, no;
    List *head1, *head2;
    head1 = head2 = NULL;

    printf("\nEnter the no of elements: ");
    scanf("%d", &n);

    while (n != 0)
    {
        printf("\nEnter a no: ");
        scanf("%d", &no);

        IncreasingSortedInsert(&head1, no);
        DecreasingSortedInsert(&head2, no);

        printf("\nList in Ascending order->\n");
        Display(head1);
        printf("\nList in Descending order->\n");
        Display(head2);

        n--;
    }

    return 0;
}

void Display(List *head)
{
    while (head)
    {
        printf("%d\t", head->value);
        head = head->next;
    }
}

List *create_node(int n)
{
    List *temp;
    temp = (List *)malloc(sizeof(List));

    temp->value = n;
    temp->next = NULL;

    return temp;
}

void IncreasingSortedInsert(List **head, int n)
{
    List *temp, *cur = *head;
    temp = create_node(n);

    if (*head == NULL || (*head)->value >= temp->value) // differ from decreasing order
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (cur->next != NULL && cur->next->value < temp->value) // differ from decreasing order
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
    return;
}

void DecreasingSortedInsert(List **head, int n)
{
    List *temp, *cur = *head;
    temp = create_node(n);

    if (*head == NULL || (*head)->value <= temp->value) // differ from increasing order
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (cur->next != NULL && cur->next->value > temp->value) ////differ from increasing order
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
    return;
}