/* WAP to check the validity of a expression by parethesis checking */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_using_list
{
    char c;
    struct stack_using_list *next;
} Stk;

Stk *s_top = NULL;

/* =============== PROTOTYPE DECLERATION ===============*/

Stk *create_node(char);
void Push(char);
char Pop();
void Display();
int match_bracket(char, char);
int parenthesis_check(char *);

int main()
{
    char *str = NULL;
    int n, check;

    printf("\nEnter the max size  of the string: ");
    scanf("%d", &n);

    str = (char *)malloc(sizeof(char) * n);

    printf("\nEnter the expression: ");
    fflush(stdin);
    gets(str);

    check = parenthesis_check(str);

    if (check == 1)
    {
        printf("\nThis is a VALID expression");
    }
    else
    {
        printf("\nThis is a INVALID expression!!!");
    }
}

Stk *create_node(char c)
{
    Stk *temp;
    temp = (Stk *)malloc(sizeof(Stk));

    temp->next == NULL;
    temp->c = c;

    return temp;
}

void Push(char c)
{
    Stk *temp;
    temp = create_node(c);

    temp->next = s_top;
    s_top = temp;
}

char Pop()
{
    Stk *temp;
    char ch;
    temp = s_top;
    s_top = s_top->next;

    ch = temp->c;
    free(temp);

    return ch;
}

int isEmpty()
{
    if (s_top == NULL)
    {
        return 1;
    }
    return 0;
}

void Display()
{
    Stk *cur = s_top;

    if (isEmpty())
    {
        printf("\nSTACK UNDERFLOW!!!");
        return;
    }
    while (cur != NULL)
    {
        printf("%d", cur->c);
        cur = cur->next;
    }
}

int bracket_check(char ch, char ch1)
{
    if (ch == '(' && ch1 == ')')
        return 1;
    else if (ch == '{' && ch1 == '}')
        return 1;
    else if (ch == '[' && ch1 == ']')
        return 1;

    return 0;
}

int parenthesis_check(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        // if any left parenthesis is found, push it into the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            Push(s[i]);
        }

        // If the symbol is right parenthesis
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (isEmpty() == 1)
            {
                return 0;
            }
            if (!bracket_check(Pop(), s[i]))
            {
                return 0;
            }
        }
    }

    return 1;
}