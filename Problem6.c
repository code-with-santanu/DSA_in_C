/* Write a program to find all the prime divisor of a number (using stack or queue) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct queue
{
    int value;
    struct queue *next;
} Que;

Que *front = NULL, *rear = NULL;

Que *create_node(int);
void Insert(int);
int Delete();
void Display();
int isPrime(int);
void PrimeDivisor(int);

int main()
{
    int n;

    printf("\nEnter a no: ");
    scanf("%d", &n);

    PrimeDivisor(n);

    printf("\nThe prime divisors of the given no are: ");
    Display();

    return 0;
}

Que *create_node(int n)
{
    Que *temp;
    temp = (Que *)malloc(sizeof(Que));
    temp->next = NULL;
    temp->value = n;

    return temp;
}

void Insert(int n)
{
    Que *temp = NULL, *cur = front;

    temp = create_node(n);
    if (rear == NULL || front == NULL)
    {
        rear = front = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int Delete()
{
    int n;
    Que *temp;
    if (front == NULL)
    {
        printf("\nQueue Underflow");
    }
    temp = front;
    n = temp->value;
    front = front->next;
    free(temp);

    return n;
}

void Display()
{
    Que *cur = front;

    if (front == NULL)
    {
        printf("\nQueue Underflow");
        return;
    }
    while (cur)
    {
        printf("%d\t", cur->value);
        cur = cur->next;
    }
}

int isPrime(int n)
{
    int count = 0, i = 2;

    while (i <= sqrt(n))
    {
        if (n % i == 0)
        {
            count++;
        }
        i++;
    }
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PrimeDivisor(int n)
{
    int i = 2;
    while (n != 1)
    {
        if (isPrime(i) == 1)
        {
            if (n % i == 0)
            {
                Insert(i);
                n /= i;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
}