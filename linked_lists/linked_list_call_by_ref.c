#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ele;
    struct node *next;
};
void prtll(struct node *);
void add1(struct node **head)
{
    struct node *n3,*temp;
    n3=(struct node*)malloc(sizeof(struct node));
        printf("enter the the element that u want to add:");
        scanf("%d",&n3->ele);
        n3->next=*head;
        *head=n3;
        printf("\nElements after adding\n");
        prtll(*head);
}
void add2(struct node **head)
{
    struct node *n2,*temp;
    n2=(struct node*)malloc(sizeof(struct node));
        printf("enter the the element that u want to add:");
        scanf("%d",&n2->ele);
        temp=*head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n2;
        n2->next=NULL;
                printf("\nElements after adding\n");
        prtll(*head);
}
void add3(struct node **head)
{
    struct node *n2,*temp,*nn;
    int c;int d,e;
n2=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element that u want to insert:");
        scanf("%d",&n2->ele);
        temp=*head;
        c=0;
         while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
        printf("Enter the index:");
        scanf("%d",&d);
        while(d<0||d>c)
        {
            printf("you entered invalid index\nEnter valid index\n");
            scanf("%d",&d);
        }
        temp=*head;
        e=0;
        if(d==0)
        {
            temp=*head;
            *head=n2;
            n2->next=temp;
        }
        else
        {

        while(e!=d-1)
        {
            temp=temp->next;
            e++;
        }
        nn=temp->next;
        temp->next=n2;
        n2->next=nn;}
                printf("\nElements after adding\n");
        prtll(*head);
    }
void remov1(struct node **head)
{
    struct node *temp;
    if(*head==NULL)
            printf("\nNO ELEMENTS FOUND\n");
        else{
        temp=*head;
        *head=temp->next;
        temp=*head;
         while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
        }
                printf("\nElements after removing\n");
        prtll(*head);
}
void remov2(struct node **head)
{
    struct node *temp;
    if(*head==NULL)
            printf("\nNO ELEMENTS FOUND\n");
        else if((*head)->next==NULL)
        {
            *head=NULL;
            printf("After removing element:\nNO ELEMENTS FOUND\n");
        }
        else{temp=*head;
        while(((temp->next)->next)!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    temp=*head;
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }}
     printf("\nElements after removing\n");
        prtll(*head);
}
void remov4(struct node **head)
{
     struct node *temp,*nn;
     temp=*head;
       int c=0,d,e;
         while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }if(*head==NULL)
    printf("\nNO ELEMENTS FOUND!!\n");
    else{
        printf("Enter the index:");
        scanf("%d",&d);
        while(d<0||d>c-1)
        {
            printf("you entered invalid index\nEnter valid index\n");
            scanf("%d",&d);
        }
        temp=*head;
        if(d==0)
        {
            *head=temp->next;
        }
        else
        {
        e=0;
        while(e!=d)
        {
            if(e==d-1)
                nn=temp;
            temp=temp->next;
            e++;
        }
        nn->next=temp->next;
        temp=*head;
    }temp=*head;
       }
        printf("\nElements after removing\n");
        prtll(*head);
}
void prtll(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("[ ");
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
    printf("]");
}
void main()
{
    struct node *head=NULL;
    struct node *temp=NULL;
    int a,b,c,d,e,opt,opt1;
    e=0;
    b=0;
    c=0;
    printf("enter the length of list:");
    scanf("%d",&a);
    struct node *nn;
        nn=(struct node*)malloc(sizeof(struct node));
        head=nn;
        temp=head;
        printf("enter element:");
        scanf("%d",&(nn->ele));
    while(b!=a-1)
    {
        struct node *n1;
        n1=(struct node*)malloc(sizeof(struct node));
        printf("enter element:");
        scanf("%d",&(n1->ele));
        temp->next=n1;
        temp=temp->next;
        b++;
    }
    temp->next=NULL;
     do{printf("\n\nENTER\n\n");
    printf("1.Add element to the first\n");
    printf("2.Add element to the last\n");
    printf("3.Add element at particular index\n");
    printf("4.Remove element from the first\n");
    printf("5.Remove element from the last\n");
    printf("6.Remove element from particular index\n");
    printf("7.Exit\n\n====>");
    scanf("%d",&opt);
    struct node*n2;
    switch(opt)
    {
    case 1:
        add1(&head);
        break;
    case 2:
        add2(&head);
        break;
    case 3:
        add3(&head);
        break;
    case 4:
        remov1(&head);
        break;
    case 5:
        remov2(&head);
        break;
    case 6:
        remov4(&head);
        break;
    case 7:
         printf("\nTHANK U\n");
        break;
    default:
        printf("\nENTER VALID OPTION\n");
    }
}while(opt!=7);}
