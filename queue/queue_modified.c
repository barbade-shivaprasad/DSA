#include<stdio.h>
struct queue
{
    int c[5];
    int rear;
    int front;
};
int rep(int front,int rear,int c[])
{
        if(front==rear)
            return 0;
        else
        {
            c[front]=c[front+1];
        front++;
        rep(front,rear,c);
        }
}
int main()
{   int front,rear,b,d;
    struct queue q;
    q.front=0;
    q.rear=0;
    do{printf("Enter\n 1.Enqueue\n 2.Dequeue\n 3.Exit\n==>");
    scanf("%d",&b);
    switch(b)
    {
    case 1:
        if(q.rear==4)
            printf("Cannot add any more...\n");
        else
        {
            printf("Enter the value:");
            scanf("%d",&d);
            q.c[q.rear]=d;
            q.rear++;
            printf("\nthe first value is %d\n\n",q.c[q.front]);
            front=q.front;
        }
        break;
    case 2:

            if(q.front==q.rear)
                printf("Queue is empty\n");
            else
            {
                rep(front,q.rear,q.c);
                q.rear--;
                if(q.front==q.rear)
                printf("Queue is empty");
                else
                printf("The front value is %d\n",q.c[0]);
            }

        break;
    case 3:
        printf("Thank u");
        break;
    default:
        printf("enter crct number\n");

    }}while(b!=3);
}
