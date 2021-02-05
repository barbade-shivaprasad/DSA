#include <stdio.h>
#include <stdlib.h>
struct node
{
    int ele;
    struct node *next;
};
struct node * enqueue(struct node *head)
{
        struct node *nn,*temp;
        nn=(struct node *)malloc(sizeof(struct node));
        printf("Enter value that you want to enqueue:");
        scanf("%d",&nn->ele);
        nn->next=NULL;
        if(head==NULL)
         {
             head=nn;
            printf("\nThe first ele is %d\n",head->ele);
         }
         else
        {
             temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        printf("\nThe first ele is %d\n",head->ele);
        }
        return head;
}
struct node * dequeue(struct node *head)
{
        struct node *temp;
        if(head==NULL)
            printf("\nFAILD\nNO ELEMENTS FOUND\n");
        else if(head->next==NULL)
           {
               head=NULL;
            printf("\nSUCCESS\nNO ELEMENTS LEFT\n");
           }
        else{
        head=head->next;
        printf("\nSUCCESS\nThe first ele is %d\n",head->ele);}
        return head;
}
int main()
{
    struct node *head=NULL;
    int opt;
    do{
    printf("\nENTER\n1.ENQUEUE\n2.DEQUEUE\n3.EXIT\n==>");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        head=enqueue(head);
        break;
    case 2:
        head=dequeue(head);
        break;
    case 3:
        printf("\nThank u\n");
        return 0;
    default:
        printf("\nEnter valid option:");
    }}while(opt!=3);
}
