#include<stdio.h>
struct stack
{
    int *a;
    int top;
    int size;
};
void main()
{
    struct stack *s;
    int b;
    int c;
    s=(struct stack *)malloc(sizeof(struct stack));
    printf("enter size of array:");
    scanf("%d",&s->size);
    s->a=(int *)malloc(s->size*sizeof(int));
    s->top=-1;
    do{
    printf("Enter\n 1  to push\n 2  to pop\n 3  to exit\n==>");
    scanf("%d",&b);
    switch(b){
    case 1:
        if(s->top==s->size-1){
            printf("The stack is full..Cannot push");
        }
        else{
            printf("enter value to push:");
            scanf("%d",&c);
            s->top++;
            s->a[s->top]=c;
            printf("Success\nThe top value is %d\n",s->a[s->top]);
        }
        break;
    case 2:
        if(s->top==-1){
            printf("The stack is empty cannot pop!");
        }
        else{

            s->top--;
            if(s->top==-1)
                printf("stack is empty");
            else
            printf("Success\nThe top value is %d\n",s->a[s->top]);
        }
        break;
    case 3:
        break;
    }}
    while(b!=3);
    return 0;
}

