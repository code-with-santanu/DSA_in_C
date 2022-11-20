#include <stdio.h>
#include <stdlib.h>

int TwoSum(int arr[10], int length, int n, int indexEx, int *index1, int *index2)
{
    int i, j, found = 0;

    int s[15];
    for (i = 0; i < 15; i++)
    {
        s[i] = -1;
    }

    for (i = 0; i < length; i++)
    {
        if (i == indexEx)
        {
            continue;
        }
        else if (s[arr[i]] > -1)
        {
            found = 1;
            *index1 = i;
            *index2 = s[arr[i]];
            printf("\nThe  indices are : [%d,%d]", i, s[arr[i]]);
            break;
        }
        else
        {
            s[n - arr[i]] = i;
        }
    }

    printf("\nTwoSumFound= %d", found);

    return found;
}

void ThreeSum(int a[10], int length, int sum)
{
    int Index1, Index2, i, rSum, f = 0;

    for (i = 0; i < length; i++)
    {

        rSum = sum - a[i];
        f = TwoSum(a, length, rSum, i, &Index1, &Index2);
        printf("\nFlag =%d", f);
        if (f == 1)
        {
            break;
        }
        }
    // if (found == 1)
    // {
    //     printf("\nThe required indices are: %d ,%d ,%d", i, Index1, Index2);
    // }

    printf("\nFound= %d", f);
    if (f == 0)
    {
        printf("\nNot Found!!!");
    }
    else
    {
        printf("\nThe required indices are: %d ,%d ,%d", i, Index1, Index2);
    }
}

int main()
{
    int ar[10] = {5, 2, 8, 7, 6, 9, 7, 6};
    int targetSum = 30;

    ThreeSum(ar, 8, targetSum);
}
