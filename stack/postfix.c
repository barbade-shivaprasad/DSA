#include<stdio.h>
#include<string.h>
struct stack
{
    /* data */
    char a[30];
    int top;
};
struct stack push(char ele,struct stack s)
{
    
        s.top++;
        s.a[s.top]=ele;
    
    return s;   
};
int prior(int a)
{
    if(a =='*' || a == '/')
    return 2;
    else if(a=='+'||a=='-')
    return 1;
    else if(a=='(')
    return 0;
    else
    return -1;
}
void main()
{
    int f,index;
    char exp[30];
    struct stack s;
    s.top=-1;
    printf("enter the expression you want to convert to postfix:");
    scanf("%s",exp);
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-' || exp[i]=='(' || exp[i]==')')
        {
            if(exp[i]=='(')
            {
                f=1;
                s=push(exp[i],s);
                index=s.top;
            }
            else if(prior(exp[i])>prior(s.a[s.top]))
            s=push(exp[i],s);
            else if(exp[i]==')')
            {   f=0;
                while(s.a[s.top]!='(')
                {
                    printf("%c",s.a[s.top]);
                    s.top--;
                }
                s.top--;
            }
            else
            {
                if(f==1)
                {
                    for(int k=index;k<=s.top;k++)
                    {
                        if(prior(s.a[k])>=prior(exp[i]))
                        {
                            printf("%c",s.a[s.top]);
                            s.top--;
                        }
                    }
                }
                else
                {
                    for(int k=0;k<=s.top+1;k++)
                    {
                        if(prior(s.a[k])>=prior(exp[i]))
                        {
                            printf("%c",s.a[s.top]);
                            s.top--;
                        }
                    }                   
                }
                s=push(exp[i],s);
            }
        }
        else
        {
            printf("%c",exp[i]);
        }
    }
    if(s.top>-1)
        for(int i=s.top;i>=0;i--)
        {
            printf("%c",s.a[i]);
            
        }

}
