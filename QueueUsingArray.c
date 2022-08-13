/*CREATE  A  STACK  USING ARRAY */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* ======== GLOBAL  DECLARATION ======== */
int *QUE, front = 0, rear = -1, size;

/* =============== PROTOTYPE DECLERATION ===============*/

void create_queue();
void Insert();
void Delete();
void Display();

int main()
{
    int ch;
    char choice;

    create_queue();
    do
    {
        system("cls");
        printf("\nPress 1 to INSERT into the queue...");
        printf("\nPress 2 to DELETE from the queue...");
        printf("\nPress 3 to DISPLAY the queue...");

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

        default:
            printf("\nYou entered wrong choice. Please enter a valid option");
            getch();
            continue;
        }

        printf("\nDo you want to continue? choose[y/n]: ");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

/* =============== FUNCTION  DEFINITIONS =============== */

void create_queue()
{
    printf("\nEnter the maximum size of the queue: ");
    scanf("%d", &size);
    QUE = (int *)malloc(size * sizeof(int));
}

void Display()
{
    if (rear == -1)
    {
        printf("\nQUEUE IS EMPTY!!!");
        return;
    }
    int *p = QUE + front, i;

    for (i = front; i <= rear; i++)
    {
        printf("%d\t", *(p++));
    }

    // int i;
    // for (i = front; i <= rear; i++)
    // {
    //     printf("%d\t", QUE[i]);
    // }
}
void Insert()
{
    // int *p = NULL, i;    /* For using pointer */
    int n;

    if (rear == size - 1)
    {
        printf("\nQUEUE OVERFLOW!!!");
        return;
    }

    // if (rear == -1) // Indicates the queue is empty
    // {
    //     front++; // assign the front value to 0
    // }

    // rear++;
    // p = QUE + front;
    // for (i = front; i < rear; i++)
    // {
    //     p++;
    // }

    printf("\nEnter the no to insert: ");
    scanf("%d", &n);

    QUE[++rear] = n; /*  insert using indexing method */
}

void Delete()
{
    int value;

    if (rear == -1)
    {
        printf("\nQUEUE UNDERFLOW!!!");
        return;
    }

    // if (front == rear) // Indicates that the queue has no ele, the front and rear reaches the end of array
    // {
    //     front = rear = -1; // set the front and rear position to the initial condition
    // }

    printf("\nThe Deleted value is: %d", QUE[front]);

    // front++; // Shifting the front towards

    /* another process for deletion */
    for (int i = front; i < rear; i++)
    {
        QUE[i] = QUE[i + 1];
    }
    rear--;
}
