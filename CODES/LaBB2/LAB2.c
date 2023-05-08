#include <stdio.h>
#include <stdlib.h>

int GCD(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return (b,a%b);
}
int main()
{
    int a=GCD(60,24);
    printf("%d",a);
}