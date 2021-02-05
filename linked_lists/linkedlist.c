#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ele;
    struct node *next;
};
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
    printf("7.Remove given element\n");
    printf("8.Exit\n\n");
    scanf("%d",&opt);
    struct node *n2;
    switch(opt)
    {
    case 1:
        n2=(struct node*)malloc(sizeof(struct node));
        printf("enter the the element that u want to add:");
        scanf("%d",&n2->ele);
        n2->next=head;
        head=n2;
        temp=head;
        printf("elements after adding:\n");
        while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
        break;
    case 2:
        n2=(struct node*)malloc(sizeof(struct node));
        printf("enter the the element that u want to add:");
        scanf("%d",&n2->ele);
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n2;
        n2->next=NULL;
        temp=head;
         while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
        break;
    case 3:
        n2=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element that u want to insert:");
        scanf("%d",&n2->ele);
        temp=head;
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
        temp=head;
        e=0;
        if(d==0)
        {
            temp=head;
            head=n2;
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
        temp=head;
        while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
    break;
    case 4:
        if(head==NULL)
            printf("\nNO ELEMENTS FOUND\n");
        else{
        temp=head;
        head=temp->next;
        temp=head;
         while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }}
    break;
    case 5:
        if(head==NULL)
            printf("\nNO ELEMENTS FOUND\n");
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
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }}
    break;
    case 6:
        temp=head;
        c=0;
         while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
        printf("Enter the index:");
        scanf("%d",&d);
        while(d<0||d>c-1)
        {
            printf("you entered invalid index\nEnter valid index\n");
            scanf("%d",&d);
        }
        temp=head;
        if(d==0)
        {
            head=head->next;
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
        temp=head;
    }temp=head;
         while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
    break;
    case 7:
        temp=head;e=0;
    printf("enter the element that u want to remove:");
    scanf("%d",&c);
    while(temp!=NULL)
    {
        if(temp->ele==c)
        {
          d=1;
          nn=temp->next;
          break;
        }
        else
        {d=0;
         temp=temp->next;}
        e++;
    }
    if(d==1)
    {
        if(e==0)
        {
            head=head->next;
        }
        else
        {   temp=head;
            while(e!=1)
            {
                temp=temp->next;
                e--;
            }
            temp->next=nn;
        }
        temp=head;
        printf("elements after removing:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
        temp=temp->next;
    }
    }
    else
        printf("Element not found!!\n");
    temp=head;
    break;
    default:
        printf("\nENTER VALID OPTION\n");
    }
    }
    while(opt!=8);
}
