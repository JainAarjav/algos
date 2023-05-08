#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b)
{
    int c;
    c=*a;
     *a=*b;
     *b=c;
     return;
}
void bubblesort(int arr[],int n)
{

    int i,j,k;
     for(i=0;i<n-1;i++)
     {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
     }
}

int main()
{
   int arr[]={5,3,5,2,3,9,1,2};
       int n=sizeof(arr)/sizeof(arr[0]);
   bubblesort(arr,n);

    for(int i=0;i<8;i++)
    {
        printf("%d \t",arr[i]);
    }

}