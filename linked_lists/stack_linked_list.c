#include <stdio.h>
#include <stdlib.h>
struct node
{
    int ele;
    struct node *next;
};
struct node * push(struct node *head)
{
        struct node *nn,*temp;
        nn=(struct node *)malloc(sizeof(struct node));
        printf("Enter value that you want to push:");
        scanf("%d",&nn->ele);
        nn->next=NULL;
        if(head==NULL)
         {
             head=nn;
            printf("\nThe top ele is %d\n",head->ele);
         }
         else
        {
             temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        printf("\nThe top ele is %d\n",(temp->next)->ele);
        }
        return head;
}
struct node * pop(struct node *head)
{
        struct node *nn,*temp;
        nn->next=NULL;
        if(head==NULL)
            printf("\nNO ELEMENTS FOUND\n");
        else if(head->next==NULL)
           {
               head=NULL;
            printf("\nSUCCESS\nNO ELEMENTS LEFT\n");
           }
        else{
        temp=head;
        while((temp->next)->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("\nSUCCESS\nThe top ele is %d\n",temp->ele);}
        return head;
}
int main()
{
    struct node *head=NULL;
    int opt;
    do{
    printf("\nENTER\n1.PUSH\n2.POP\n3.EXIT\n==>");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        head=push(head);
        break;
    case 2:
        head=pop(head);
        break;
    case 3:
        return 0;
    default:
        printf("\nEnter valid option:");
    }}while(opt!=3);
}
