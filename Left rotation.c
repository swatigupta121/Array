#include<stdio.h>
#include<stdlib.h>
void enqueue(int *rear,int *front,int a[],int size,int x);
int dequeue(int *rear,int *front,int a[],int size);
void display(int rear,int front,int a[],int size);
int main()
{
    int  x,i,val,*front=-1,n,*rear=-1,j,size;
    int a[10];
    //printf("enter size of array: ");
    scanf("%d",&size);
    //printf("enter no of rotation: ");
    scanf("%d",&n);
    for(i=0;i<size;i++)
    {
        //printf("enter the element to be inserted\n");
        scanf("%d",&x);
        enqueue(&rear,&front,a,size,x);
    }
    /*for(i=0;i<size;i++)
    {
        printf("%d",a[i]);
    }*/
    for(j=0;j<n;j++)
    {
        val=dequeue(&rear,&front,a,size);
        //printf("\nvalue of val: %d\n",val);
        if(val!=-1)
        {
            enqueue(&rear,&front,a,size,val);
        }
        else
        {
            return;
        }
    }
    display(rear,front,a,size);
}
void enqueue(int *rear,int *front,int a[],int size,int x)
{
    if((*rear+1)%size==*front)
    {
        printf("full");
    }
    else
    {
        if(*rear==-1&&*front==-1)
        {
            *rear=0;
            *front=0;
            a[*rear]=x;
        }

        else

        {

            *rear=(*rear+1)%size;
          a[*rear]=x;
            //  *rear=*rear+1
            //    *front=*front+1;

        }
    }
}
int dequeue(int *rear,int *front,int a[],int size)
{
    int y;
    if(*front==-1&&*rear==-1)
    {
        printf("empty");
        return -1;
    }
    else if(*rear==*front)
    {
        *rear=-1;
        *front=-1;
        return -1;
    }
    else
    {
        //printf("deleted ele is %d",a[*front]);
        y=a[*front];
    //  *front=*front+1;
        *front=(*front+1)%size;
        return y;
    }
    //x=a[*front];
}
display(int rear,int front,int a[],int size)
{
    int i=front;
    //  int rear,front;
    if(front==-1&&rear==-1)
    {
        printf("empty");
    }
    else
    {
        while(i!=rear)
        {
            printf("%d ",a[i]);
            i=(i+1)%size;
          //  i++;
        }
        printf("%d",a[i]);
    }
}
