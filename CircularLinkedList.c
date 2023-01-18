#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Cir_Linked_List
{
    int value;
    struct Cir_Linked_List *next;
} NODE;

// Global  declaration
NODE *head = NULL;

/* =============== PROTOTYPE DECLERATION ===============*/
NODE *create_node(int);
void create_list();
void Display();
void insert_at_begin();
void insert_at_end();
void insert_before();
void insert_after();
void Insert();
void delete_from_begin();
void delete_from_end();
void delete_from_middle();
void Delete();
void Search();
void Bubble_sort();
void Reverse_list();

int main()
{
    int ch, no;
    char choice;

    create_list();

    do
    {
        system("cls");
        printf("\nPress 1 to DISPLAY the list...");
        printf("\nPress 2 to INSERT a number to the list...");
        printf("\nPress 3 to DELETE any node from the list....");
        printf("\nPress 4 to SEARCH a no from the list...");
        printf("\nPress 5 to SORT the list...");
        printf("\nPress 6 to REVERSE the list...");
        printf("\nPress 7 to EXIT the program...");

        scanf("\n%d", &ch);
        switch (ch)
        {
        case 1:
            Display();
            break;

        case 2:
            Insert();
            break;

        case 3:
            Delete();
            break;

        case 4:
            Search();
            break;

        case 5:
            Bubble_sort();
            break;

        case 6:
            Reverse_list();
            break;

        case 7:
            exit(1);
        default:
            printf("\nYou entered wrong choice!!!");
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

NODE *create_node(int value)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));

    temp->next = NULL;
    temp->value = value;

    return temp;
}

void create_list()
{
    NODE *temp, *current;
    current = temp = NULL;
    int n, b_num;
    char choice;

    do
    {
        printf("\nEnter the no to insert: ");
        scanf("%d", &n);
        temp = create_node(n);

        if (head == NULL)
        {
            head = current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
            temp->next = head; /* Differ from singly linked list */
        }

        printf("\nTo insert more no choose[y/n]: ");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void Display()
{
    NODE *curr = head;

    do
    {
        printf("%d\t", curr->value);
        curr = curr->next;   
    } while (curr!=head);

    printf("%d",curr->value);   //converges to head
    
}

void insert_at_begin()
{
    NODE *temp = NULL,*cur=head;
    int no;

    printf("\nEnter the no want to insert: ");
    scanf("%d", &no);

    temp = create_node(no);
    do
    {
        cur=cur->next;
    } while (cur->next!=head);
    
    temp->next = head;
    cur->next=temp;
    head = temp;
}

void insert_at_end()
{
    NODE *temp, *current;
    int no;

    temp = current = NULL;

    printf("\nEnter the no want to insert: ");
    scanf("%d", &no);

    temp = create_node(no);

    current = head;
    do
    {
        current = current->next;
    }while (current->next != head);
    temp->next=head;
    current->next = temp;
}

void insert_before()
{
    NODE *temp, *current;
    int new_no, b_num, found = 0;
    temp = current = NULL;

    printf("\nEnter the no to insert in the list: ");
    scanf("%d", &new_no);
    printf("\nEnter the no before which want to insert: ");
    scanf("%d", &b_num);

    temp = create_node(new_no);
    if (head->value == b_num)
    {
        insert_at_begin();
        found = 1;
    }
    else
    {
        current = head;
        do
        {
            if (current->next->value == b_num)
            {
                temp->next = current->next;
                current->next = temp;
                found = 1;
                break;
            }
            current = current->next;
        }while (current->next != head);
    }

    if (found == 0)
    {
        printf("\nThe no %d ,after which you want to insert is not in the list!!!", b_num);
    }
}

void insert_after()
{
    NODE *temp, *current;
    int new_no, a_num, found = 0;

    temp = current = NULL;

    printf("\nEnter the no to insert in the list: ");
    scanf("%d", &new_no);
    printf("\nEnter the no after which want to insert: ");
    scanf("%d", &a_num);

    temp = create_node(new_no);

    current = head;
    do
    {
        if (current->value == a_num)
        {
            temp->next = current->next;
            current->next = temp;
            found = 1;
            break;
        }
        current = current->next;
    }while (current != head);

    if (found == 0)
    {
        printf("\nThe no %d ,after which you want to insert is not in the list!!!", a_num);
    }
}

void Insert()
{
    int c;
    char choice;

    do
    {
        printf("\nPress 1 to insert at begin...");
        printf("\nPress 2 to insert at end...");
        printf("\nPress 3 to insert before any no...");
        printf("\nPress 4 to insert after any no...");

        scanf("\n%d", &c);

        switch (c)
        {
        case 1:
            insert_at_begin();
            break;

        case 2:
            insert_at_end();
            break;

        case 3:
            insert_before();
            break;

        case 4:
            insert_after();
            break;
        default:
            printf("\nYou enetered wrong option!!!");
            getch();
            continue;
        }
        printf("\nDo you want to insert again?choose[y/n]: ");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void delete_from_begin()
{
    NODE *temp=head,*cur=head;

    do
    {
        cur=cur->next;
    } while (cur->next!=head);
    cur->next=head->next;
    head=head->next;

    printf("\nThe deleted no is: %d",temp->value);
    free(temp);
}

void delete_from_end()
{
    NODE *current=head,*temp=NULL;

    do
    {
        if (current->next->next == head)
        {
            temp=current->next;
            current->next = head;

            printf("\nThe deleted no is: %d",temp->value);
            free(temp);
            break;
        }
        current = current->next;
    }while(current->next!=head);
}

void delete_from_middle()
{
    NODE *current = NULL,*temp=NULL;
    int no, found = 0;

    printf("\nEnter a no want to delete: ");
    scanf("%d", &no);

    current = head;
    do
    {
        if (current->next->value == no)
        {
            temp=current->next;
            current->next = current->next->next;

            printf("\nThe deleted no is: %d",temp->value);
            free(temp);
            found = 1;
            break;
        }
        current = current->next;
    }while (current->next != head);

    if (found == 0)
    {
        printf("\nThe no %d ,after which you want to delete is not in the list!!!", no);
    }
}

void Delete()
{
    int c;
    char choice;

    do
    {
        printf("\nPress 1 to delete from begin of the list...");
        printf("\nPress 2 to delete from end of the list...");
        printf("\nPress 3 to delete any no from the list...");

        scanf("\n%d", &c);

        if (head != NULL)
        {
            switch (c)
            {
            case 1:
                delete_from_begin();
                break;

            case 2:
                delete_from_end();
                break;

            case 3:
                delete_from_middle();
                break;

            default:
                printf("\nYou enetered wrong option!!!");
                getch();
                continue;
            }
            printf("\nDo you want to delete again?choose[y/n]: ");
            fflush(stdin);
            scanf("%c", &choice);
        }

        else
        {
            printf("\nNothing to delete!!! The list is empty");
            break;
        }
    } while (choice == 'y' || choice == 'Y');
}

void Search()
{
    NODE *current;
    int n, check = 0, count = 0;

    printf("\nEnter the value of data want to search: ");
    scanf("%d", &n);

    current = head;
    do
    {
        if (current->value == n)
        {
            check = 1;
            printf("\nData found at position %d and it's stored at address %d", count, current->next);
            break;
        }
        current = current->next;
        count++;
    }while (current != head);

    if (check == 0)
    {
        printf("\nData is not found in the list!!!");
    }
}

void Reverse_list()
{
    NODE *current, *prev, *sprev;
    current = head;
    prev = sprev = NULL;

    do
    {
        sprev = prev;
        prev = current;
        current = current->next;
        prev->next = sprev;
    }while (current != head);
    
    head = prev;
    current->next=head;
}

void Bubble_sort()
{
    NODE *current = head, *cur = NULL;
    int t;

    do
    {
        cur = current->next;
        do
        {
            if (current->value > cur->value)
            {
                t = current->value;
                current->value = cur->value;
                cur->value = t;
            }
            cur = cur->next;
        
        }while (cur != head);

        current = current->next;
    } while (current->next != head);
}