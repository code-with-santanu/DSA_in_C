#include<stdio.h>
#include<stdlib.h>

void InsertInArray(int arr[],int );
void Print(int arr[],int );
int LinearSearch(int arr[],int ,int );
int BinarySearch(int arr[],int ,int );
int InterpolationSearch(int arr[],int , int );


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


    //choose any one algo and comment rest to algo before run the program
    searchIndex=LinearSearch(a,size,targetNo);        
    searchIndex=BinarySearch(a,size,targetNo);
    searchIndex=InterpolationSearch(a,size,targetNo);

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
        // If no is larger, no is in upper part
        else if(arr[mid] < targetNo)
        {
            low=mid+1;
        }
        //If no is smaller, no is in the lower part
        else
        {
            high =mid-1;
        }
    }

    return -1;
}


//Applicable for sorted array and data should be uniformly distributed
int InterpolationSearch(int arr[],int size, int targetNo)
{
    int low,pos,high;
    low=0;
    high=size-1;

    //for 1 ele present in array(to avoid zero devision error)
    if(size==1)
    {
        if(arr[0]==targetNo)
            return 0;
        else
            return -1;
    }

    while (low<=high)
    {
        pos = low + (((targetNo-arr[low]) / (arr[high]-arr[low])) * (high-low));
        if(arr[pos]==targetNo)
        {
            return pos;
        }
        // If no is larger, no is in upper part
        else if(arr[pos]<targetNo)
        {
            low = pos+1;
        }
        //If no is smaller, no is in the lower part
        else
        {
            high = pos-1;
        }
    }
    
    return -1;
}