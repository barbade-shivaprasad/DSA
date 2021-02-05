#include<stdio.h>
struct queue
{
    int c[5];
    int r;
};
int a(int b,int c[5])
{
    if(b==4)
    {
        return 0;
    }
    else
    {
        c[b]=c[b+1];
        b++;
        return a(b,c);
    }
}
int main()
{   int b,d;
    struct queue q;
    q.r=-1;
    do{printf("Enter\n 1.Enqueue\n 2.Dequeue\n 3.Exit\n==>");
    scanf("%d",&b);
    switch(b)
    {
    case 1:
        if(q.r==4)
            printf("Cannot add any more...\n");
        else
        {
            q.r++;
            printf("Enter the value:");
            scanf("%d",&d);
            q.c[q.r]=d;
            printf("\nthe first value is %d\n\n",q.c[0]);
        }
        break;
    case 2:
        if(q.r==-1)
            printf("\nempty!!!\n");
        else
        {
            a(0,q.c);
            q.r--;
            printf("\nthe first value is %d\n",q.c[0]);
        }
        break;
    case 3:
        printf("Thank u");
        break;
    default:
        printf("enter crct number\n");

    }}while(b!=3);
}
