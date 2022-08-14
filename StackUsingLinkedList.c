/*CREATE  A  STACK  USING ARRAY */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct stack_using_list
{
    int value;
    struct stack_using_list *next;
} STACKNODE;

/* ======== GLOBAL  DECLARATION ======== */
int size;
STACKNODE *top = NULL;

/* =============== PROTOTYPE DECLERATION ===============*/

STACKNODE *create_node(int);
void Push();
void Pop();
void Display();
void Delete_stk();

int main()
{
    int ch;
    char choice;

    do
    {
        system("cls");
        printf("\nPress 1 to PUSH element into the stack...");
        printf("\nPress 2 to POP from the stack...");
        printf("\nPress 3 to DISPLAY the  stack...");
        printf("\nPress 4 to DELETE the whole stack...");

        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Push();
            break;

        case 2:
            Pop();
            break;

        case 3:
            Display();
            break;

        case 4:
            Delete_stk();
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

STACKNODE *create_node(int n)
{
    STACKNODE *temp;
    temp = (STACKNODE *)malloc(sizeof(STACKNODE));
    temp->next = NULL;
    temp->value = n;

    return temp;
}

void Push()
{
    STACKNODE *temp;
    int no;

    printf("\nEnter the no to push: ");
    scanf("%d", &no);

    temp = create_node(no);
    if (temp == NULL)
    {
        printf("\nSTACK OVERFLOW!!!");
        return;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void Pop()
{
    STACKNODE *temp;

    if (top == NULL)
    {
        printf("\nSTACK UNDERFLOW!!!");
        return;
    }

    temp = top;
    top = top->next;
    printf("\nThe popped value is: %d", temp->value);
    free(temp);
}

void Display()
{
    STACKNODE *head;
    head = top;
    while (head != NULL)
    {
        printf("\n%d", head->value);
        head = head->next;
    }
}

void Delete_stk()
{
    free(top);
    exit(0);
}