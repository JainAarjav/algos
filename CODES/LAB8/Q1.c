#include <stdio.h>
#include <stdlib.h>

void insert(int A[],int n)
{
    int temp,i;
    i=n;
    temp=A[n];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;

}

void swap(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}

void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(&A[i],&A[j]);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}
void delete(int A[],int n)
{
    int x=A[n];
    int i,j,val;
    val=A[1];
    A[1]=A[n];
    A[n]=val;
    i=1,j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
        j=j+1;
        if(A[i]<A[j])
        {
        swap(&A[i],&A[j]);
        i=j;
        j=2*i;
        }
        else 
        break;
    }
   
}

int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    for(int i=2;i<8;i++)
    insert(H,i);
    delete(H,7);
     for(int j=1;j<8;j++)
     {
        printf("%d ",H[j]);
     }
}