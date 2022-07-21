/*CREATE  A  STACK  USING ARRAY */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* ======== GLOBAL  DECLARATION ======== */
int *stk, top = -1, size;

/* =============== PROTOTYPE DECLERATION ===============*/

void create_stk();
void Push();
void Pop();
void Display();

int main()
{
	int ch;
	char choice;

	create_stk();
	do
	{
		system("cls");
		printf("\nPress 1 to PUSH into the stack...");
		printf("\nPress 2 to POP from the stack...");
		printf("\nPress 3 to DISPLAY the stack...");

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

void create_stk()
{
	printf("\nEnter the maximum size of the stack: ");
	scanf("%d", &size);
	stk = (int *)malloc(size * sizeof(int));
}

void Display()
{
	int *p = stk, i;

	for (i = 0; i <= top; i++)
	{
		printf("%d\t", *(p++));
	}
}

void Push()
{
	int *p = stk, i;

	if (top == size - 1)
	{
		printf("\nSTACK OVERFLOW!!!");
	}
	else
	{
		for (i = 0; i <= top; i++)
		{
			p++;
		}
		printf("\nEnter a no: ");
		scanf("%d", p);
		top++;

		/*stk[++top] = n; //pushing the value using indexing method */
	}
}

void Pop()
{
	if (top == -1)
	{
		printf("\nSTACK UNDERFLOW!!!");
	}
	else
	{
		printf("\nThe popped value is %d", stk[top--]);
	}
}