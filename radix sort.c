#include<stdio.h>
void countsort(int a[],int n,int exp);
void radixsort(int a[],int n);
int getMax(int a[],int n);
int main()
{
    int a[100],n,i;
    printf("ENTER SIZE OF ARRAY: ");
    scanf("%d",&n);
    printf("ENTER ELEMENTS OF ARRAY: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    radixsort(a,n);
    printf("\nRADIX SORT: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int getMax(int a[],int n)
{
    int mx=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>mx)
        {
            mx=a[i];
        }
    }
    return mx;
}
void radixsort(int a[],int n)
{
    int m=getMax(a,n);
    for(int exp=1;m/exp>0;exp*=10)
    {
        countsort(a,n,exp);
    }
}
void countsort(int a[],int n,int exp)
{
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++)
    {
        count[(a[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
