#include<stdio.h>
#include<stdlib.h>


int LinearSearch(int arr[],int size,int targetNo)
{
    int i;

    for(i=0;i<size;i++)
    {
        if(arr[i]==targetNo)
        {
            return i;
        }
    }

    return -1;
}


//Only for sorted array and can't be used in linked list
int BinarySearch(int arr[],int size,int targetNo)
{
    int low,mid,high;
    low=0;
    high=size-1;

    //keep searching until low and high converges
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==targetNo)
        {
            return mid;
        }
        else if(arr[mid] < targetNo)
        {
            low=mid+1;
        }
        else
        {
            high =mid-1;
        }
    }

    return -1;
}

void InsertInArray(int arr[],int size)
{
    int i,n;

    for(i=0;i<size;i++)
    {
        printf("\nEnter a no: ");
        scanf("%d",&n); 
        arr[i]=n;   
    }

}

void Print(int arr[],int size)
{
    int i;

    printf("\nThe array: ");
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int *a;
    int size,targetNo,searchIndex;

    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    a=(int*)malloc(sizeof(int)*size);

    InsertInArray(a,size);
    Print(a,size);
    printf("\nEnter a no from the array to search: ");
    scanf("%d",&targetNo);


    // searchIndex=LinearSearch(a,size,targetNo);        
    searchIndex=BinarySearch(a,size,targetNo);

    if(searchIndex==-1)
    {
        printf("\nThe no(%d) you are searching is not in the array.",targetNo);
    }
    else
    {
        printf("\nThe no(%d) you are searching is at %d th position in the array.",targetNo,searchIndex);
    }

    return 0;

}