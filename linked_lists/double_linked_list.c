#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int ele;
    struct node *next;
};
struct node* ptf(struct node* head)
{
    struct node *temp,*nn;
    temp=head;
    printf("[");
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        nn=temp;
        temp=temp->next;
    }
    temp=nn;
    printf("]\n[");
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->prev;
    }
    printf("]");
    return head;
}
struct node* create_list()
{   
    int size,c;
    c=1;
    struct node* head=NULL;
    struct node* temp,*nn,*n1;
    printf("\nenter the size of the list:\n");
    scanf("%d",&size);
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d",&nn->ele);
    nn->next=NULL;
    nn->prev=NULL;
    head=nn;
    temp=head;
    while(c!=size)
    {
        n1=(struct node*)malloc(sizeof(struct node));
         printf("Enter the element:\n");
        scanf("%d",&n1->ele);
        temp->next=n1;
        n1->prev=temp;
        n1->next=NULL;
        temp=temp->next;
        c++;
    }
    return head;
}
struct node* add1(struct node* head)
{
    struct node* nn;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d",&nn->ele);
    nn->next=head;
    if(head!=NULL)
    head->prev=nn;
    nn->prev=NULL;
    head=nn;
    ptf(head);
    return head;

}
struct node* add2(struct node* head)
{
     struct node* nn,*temp;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d",&nn->ele);
    temp=head;
    if(temp==NULL)
    printf("\nNo elements found!!\n");
    else
    {
        while (temp->next!=NULL)
        {
            /* code */
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
        nn->next=NULL;
    }
    ptf(head);
    return head;
}
struct node * add3(struct node* head)
{   
    int c,in;              
     struct node* nn,*temp;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d",&nn->ele);
    temp=head;
    printf("\nEnter index:");
        scanf("%d",&in);
    if(in==0)
    {
        nn->next=head;
        if(head!=NULL)
         {
             head->prev=nn;
         }
        nn->prev=NULL;
        head=nn;
    }
    else
    {
    c=0;
    while(temp->next!=NULL)
    {
        c++;
        if(c==in)
        break;
        temp=temp->next;
    }
    while(in<0 || in>c+1)
    {
        printf("\nEnter valid index\n==>");
        scanf("%d",&in);
    }
    temp=head;
        c=0;
    while(temp->next!=NULL)
    {
        c++;
        if(c==in)
        break;
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        temp->next=nn;
        nn->prev=temp;
        nn->next=NULL;
    }
    else
    {
        nn->next=temp->next;
    (temp->next)->prev=nn;
    temp->next=nn;
    nn->prev=temp;
    }
    }
    ptf(head);
    return head;
}
struct node* remov1(struct node* head)
{
    if(head==NULL)
    printf("\nNo elements found!!\n");
    else
    {
        head=head->next;
        if(head!=NULL)
        {
             head->prev=NULL;
             ptf(head);
        }
    }
    return head;
}
struct node *remov2(struct node *head)
{
     struct node *temp;
    if(head==NULL)
    {
        printf("\nNO ELEMENTS FOUND\n");
    }
        else if(head->next==NULL)
        {
            head=NULL;
            printf("After removing element:\nNO ELEMENTS FOUND\n");
        }
        else{temp=head;
        while(((temp->next)->next)!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
   ptf(head);
   }
        return head;
}
struct node* remov3(struct node *head)
{
     int c,in,f;              
     struct node *temp;
    temp=head;
    printf("\nEnter index:");
        scanf("%d",&in);
    if(head!=NULL)
    if(in==0)
    {
        if(head==NULL)
    printf("\nNo elements found!!\n");
    else
    {
        head=head->next;
        if(head!=NULL)
        {
             head->prev=NULL;
             ptf(head);
        }
    }return head;}
    else{
    c=0;
    while(temp->next!=NULL)
    {
        c++;
        if(c==in)
        {
            f=1;
            break;
        }
        temp=temp->next;
    }
    if(f!=1)
    {
    while(in<0 || in>c)
    {
        printf("\nEnter valid index\n==>");
        scanf("%d",&in);
    }
    temp=head;
        c=0;
    while(temp->next!=NULL)
    {
        c++;
        if(c==in)
        break;
        temp=temp->next;
        if(in==0)
    {
        if(head==NULL)
    printf("\nNo elements found!!\n");
    else
    {
        head=head->next;
        if(head!=NULL)
        {
             head->prev=NULL;
             ptf(head);
        }
    }
    return head;
    }
    }}
   
    if(temp->next->next==NULL)
    {
        remov2(head);
    }
    else
    {   
        temp->next=temp->next->next;
        temp->next->prev=temp;
        ptf(head);
    }}
    else
    printf("\nNo elements found!!\n");
    return head;
}
void main()
{   
    int opt;
    struct node *head=NULL;

    head=create_list();
    do{printf("\n\nENTER\n\n");
    printf("1.Add element to the first\n");
    printf("2.Add element to the last\n");
    printf("3.Add element at particular index\n");
    printf("4.Remove element from the first\n");
    printf("5.Remove element from the last\n");
    printf("6.Remove element from particular index\n");
    printf("7.Exit\n\n");
    scanf("%d",&opt);
    switch (opt)
    {
    case 1:
        head=add1(head);
        break;
    case 2:
        head=add2(head);
        break;
    case 3:
        head=add3(head);
        break;
    case 4:
        head=remov1(head);
        break;
    case 5:
        head=remov2(head);
        break;
    case 6:
        head=remov3(head);
        break;
    case 7:
        printf("Thank you!!\n");
        break;
    default:
        printf("Enter valid number\n");
        break;
    }
    }while(opt!=7);
}