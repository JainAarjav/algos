#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int arr[]={1,2,3,4};

    int n=4;
    int *arr1=calloc(5,sizeof(int));
    int i,j,k=0,l=0;
    int sum=0;
    for( i=0;i<(1<<n);i++)
    {
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                arr1[k++]=arr[j];
                sum=sum+arr[j];
            }
            else
            {
                arr1[j]=0;
            }
        }
        
        for(l=0;arr1[l]!=0;l++)
        {
            printf("%d\t",arr1[l]);
           
        }
        
        sum=0;
        k=0;
        printf("\n");
    }
}