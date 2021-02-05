#include<stdio.h>
struct stack
{
    int a[5];
    int top;
    int max;
};
int push(struct stack);
int pop(struct stack);
int exit1(int);
int basic(struct stack);
void main()
{
    struct stack s;
    s.top=-1;
    basic(s);
}
int basic(struct stack s)
{   int b;
    s.max=5;
    printf("Enter\n 1  to push\n 2  to pop\n 3  to exit\n==>");
    scanf("%d",&b);
    if(b==1)
        push(s);
    else if(b==2)
        pop(s);
    else
        exit1(b);
}
int push(struct stack s)
{   int c;
    if(s.top==s.max){
            printf("The stack is full..Cannot push");
        }
        else{
            printf("enter value to push:");
            scanf("%d",&c);
            s.top++;
            s.a[s.top]=c;
            printf("Success\nThe top value is %d",s.a[s.top]);
        }
        basic(s);
}
int pop(struct stack s)
{
    if(s.top==-1){
            printf("The stack is empty cannot pop!");
        }
        else{

            s.top--;
            if(s.top==-1)
                printf("stack is empty\n");
            else
            printf("Success\nThe top value is %d\n",s.a[s.top]);
        }
        basic(s);
}
int exit1(int b)
{
    printf("you are out!");
    return 0;
}

