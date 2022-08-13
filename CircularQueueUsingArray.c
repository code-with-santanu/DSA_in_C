/*CREATE  A  STACK  USING ARRAY */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* ======== GLOBAL  DECLARATION ======== */
int *QUE, front = 0, rear = -1, size, count = 0;

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
    int i, x;

    if (count == 0)
    {
        printf("\nQUEUE IS EMPTY!!!");
        return;
    }
    else
    {
        x = front;
        for (i = 1; i <= count; i++)
        {
            printf("%d\t", QUE[x]);
            x = (x + 1) % size;
        }
    }
}

void Insert()
{
    int n;

    if (count == size)
    {
        printf("\nQUEUE  OVERFLOW!!!");
        return;
    }
    else
    {
        printf("\nEnter a no to insert: ");
        scanf("%d", &n);

        rear = (rear + 1) % size;
        QUE[rear] = n;
        count++;
    }
}

void Delete()
{
    int n;

    if (count == 0)
    {
        printf("\nQUEUE  UNDERFLOW!!!");
        return;
    }
    else
    {
        printf("\nThe deleted element is: %d", QUE[front]);
        front = (front + 1) % size;
        count--;
    }
}