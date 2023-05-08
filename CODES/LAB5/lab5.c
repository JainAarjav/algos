#include<stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}


int partition(int arr[],int l,int h)
{
    int i=l,j=h;
    int pivot=arr[l];
    do
    {
        do
        {
            i++;
        } while (arr[i]<=pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);
        
        
    } while (i<j);

    swap(&arr[l],&arr[j]);
    return j;
}

void quicksort(int arr[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(arr,l,h);
        quicksort(arr,l,j);
        quicksort(arr,j+1,h);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3,INT32_MAX},n=11,i;
quicksort(A,0,n-1);
for(i=0;i<11;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}