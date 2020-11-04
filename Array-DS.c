#include<stdio.h>
void reverse_array(int a[],int n);
int main()
{
    int a[100000],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    reverse_array(a,n);
}
void reverse_array(int a[],int n)
{
    int i;
    i=n-1;
    for(i;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}
