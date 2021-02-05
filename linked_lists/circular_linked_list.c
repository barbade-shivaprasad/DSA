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
    int a=0;
    temp=head;
    printf("[");
    while(a!=1)
    {
        if(temp->next==head)
        {
            a++;
        }
        printf("%d ",temp->ele);
        nn=temp;
        temp=temp->next;
    }
    printf("]\n[");
    temp=nn;
    a=0;
    while(a!=1)
    {
        if(temp->prev==nn)
        a++;
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
    head=nn;
    nn->next=head;
    nn->prev=head;
    temp=head;
    while(c!=size)
    {
        n1=(struct node*)malloc(sizeof(struct node));
         printf("Enter the element:\n");
        scanf("%d",&n1->ele);
        temp->next=n1;
        n1->prev=temp;
        n1->next=head;
        head->prev=n1;
        temp=temp->next;
        c++;
    }
    ptf(head);
    return head;
}
struct node* add1(struct node* head)
{
    struct node* nn;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d",&nn->ele);
    nn->prev=head->prev;
    nn->prev->next=nn;
    nn->next=head;
    head->prev=nn;
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
    while (temp->next!=head)
        {
            /* code */
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
        nn->next=head;
        head->prev=nn;
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
        nn->prev=head->prev;
        head->prev=nn;
        nn->prev->next=nn;
        head=nn;
    }
    else
    {
    c=0;
    while(temp->next!=head)
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
    while(temp->next!=head)
    {
        c++;
        if(c==in)
        break;
        temp=temp->next;
    }
        nn->next=temp->next;
        (temp->next)->prev=nn;
        temp->next=nn;
        nn->prev=temp;
    }
    ptf(head);
    return head;
}
struct node* remov1(struct node* head)
{
    if(head==NULL)
    printf("\nNo elements found!!\n");
    else if(head->next==head)
    head=NULL;
    else
    {
        head->next->prev=head->prev;
        head->prev->next=head->next;
        head=head->next;
        ptf(head);
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
        else if(head->next==head)
        {
            head=NULL;
            printf("No elements left\n");
        }
        else{temp=head;
        while(((temp->next)->next)!=head)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
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
        if(head->next==head)
    head=NULL;
    else
    {
        head->next->prev=head->prev;
        head->prev->next=head->next;
        head=head->next;
        ptf(head);
    }
    }return head;}
    else{
    c=0;
    while(temp->next!=head)
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
    while(temp->next!=head)
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
        if(head->next==head)
    head=NULL;
    else
    {
        head->next->prev=head->prev;
        head->prev->next=head->next;
        head=head->next;
        ptf(head);
    }
    }return head;
    }}}

    if(temp->next->next==head)
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
