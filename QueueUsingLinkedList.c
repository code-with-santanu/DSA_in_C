/*CREATE  A  QUEUE  USING ARRAY */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct queue_using_list
{
    int value;
    struct queue_using_list *next;
} QUEUENODE;

/* ======== GLOBAL  DECLARATION ======== */
int size;
QUEUENODE *front = NULL, *rear = NULL;

/* =============== PROTOTYPE DECLERATION ===============*/

QUEUENODE *create_node(int);
void Insert();
void Delete();
void Display();
void Delete_que();

int main()
{
    int ch;
    char choice;

    do
    {
        system("cls");
        printf("\nPress 1 to INSERT element into the queue...");
        printf("\nPress 2 to DELETE from the queue...");
        printf("\nPress 3 to DISPLAY the queue...");
        printf("\nPress 4 to DELETE the whole queue...");

        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Insert();
            break;

        case 2:
            Delete();
            break;

        case 3:
            Display();
            break;

        case 4:
            Delete_que();
            break;

        default:
            printf("\nYou entered wrong choice. Please enter a valid option");
            getch();
            continue;
        }

        printf("\nDo you want to continue? Choose[y/n]: ");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

/* =============== FUNCTION  DEFINITIONS =============== */
QUEUENODE *create_node(int n)
{
    QUEUENODE *temp;
    temp = (QUEUENODE *)malloc(sizeof(QUEUENODE));
    temp->next = NULL;
    temp->value = n;

    return temp;
}

void Insert()
{
    QUEUENODE *temp = NULL;
    int no;

    printf("\nEnter the no to insert: ");
    scanf("%d", &no);

    temp = create_node(no);

    if (rear == NULL || front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void Delete()
{
    QUEUENODE *temp;

    if (front == NULL)
    {
        rear = front = NULL;
        printf("\nQUEUE  UNDERFLOW!!!");
        return;
    }

    temp = front;
    front = front->next;

    printf("\nThe deleted value is: %d", temp->value);
    free(temp);
}

void Display()
{
    QUEUENODE *current = front;

    while (current != NULL)
    {
        printf("%d\t", current->value);
        current = current->next;
    }
}

void Delete_que()
{
    free(front);
    exit(0);
}