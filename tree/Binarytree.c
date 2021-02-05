#include<stdio.h>
#include<stdlib.h>
struct tnode
{
    struct tnode *left;
    int ele;
    struct tnode *right;
};
struct node
{
    struct tnode *ele;
    struct node *next;
};
struct node * enqueue(struct tnode *e1,struct node *head)
{
        struct node *nn,*temp;
        nn=(struct node *)malloc(sizeof(struct node));
        nn->ele=e1;
        nn->next=NULL;
        if(head==NULL)
         {
             head=nn;
         }
         else
        {
             temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
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
           }
        else{
        head=head->next;
        }
        return head;
}
int print(struct tnode  *nn)
{
    struct tnode *temp;
    struct node *head=NULL;
    if(nn==NULL)
        printf("[]");
    else
    {
        head=enqueue(nn,head);
        printf("[");
        temp=head->ele;
        printf("%d ",temp->ele);
        while(temp!=NULL)
        {
            if(head==NULL)
            temp=NULL;
            else
            {


                temp=head->ele;
                head=dequeue(head);
                if(temp->right ==NULL && temp->left==NULL)
                    break;
                if(temp->left!=NULL)
                {
                    head=enqueue(temp->left,head);
                    printf("%d ",temp->left->ele);
                }
                if(temp->right!=NULL)
                {
                    head=enqueue(temp->right,head);
                    printf("%d ",temp->right->ele);
                }

            }
        }
        printf("]");
    }

    return 0;
}
struct tnode* add(struct tnode* nn)
{
    struct tnode *temp,*n1;
    struct node *head=NULL;
    if(nn==NULL)
    {
        n1=(struct tnode*)malloc(sizeof(struct tnode));
                printf("\nEnter the element that you want to add:");
                scanf("%d",&n1->ele);
                n1->left=NULL;
                n1->right=NULL;
                return n1;
    }
    else
    {
        head=enqueue(nn,head);
        temp=head->ele;
        while(temp!=NULL)
        {
            if(head==NULL)
            temp=NULL;
            else
            temp=head->ele;
        head=dequeue(head);

            if(temp->left==NULL)
            {
                n1=(struct tnode*)malloc(sizeof(struct tnode));
                printf("\nEnter the element that you want to add:");
                scanf("%d",&n1->ele);
                temp->left=n1;
                n1->left=NULL;
                n1->right=NULL;
                break;

            }
            else
                head=enqueue(temp->left,head);
            if(temp->right==NULL)
            {
                n1=(struct tnode*)malloc(sizeof(struct tnode));
                printf("\nEnter the element that you want to add:");
                scanf("%d",&n1->ele);
                temp->right=n1;
                n1->left=NULL;
                n1->right=NULL;
                break;
            }
            else
            {
                head=enqueue(temp->right,head);
            }
    }
    }
    return nn;

}
struct tnode* del(struct tnode* nn)
{
    struct tnode *temp,*n1,*f1,*temp1;
    struct node *head=NULL;
    int f,f2;
    f2=0;
    printf("\n\nEnter the element that you want to delete:");
    scanf("%d",&f);
    temp1=nn;
    if(nn->left==NULL && nn->right==NULL)
    {
            printf("\n Every element got deleted...No element found");
            nn=NULL;
            return nn;
    }
    else
    {
        head=enqueue(nn,head);
        temp=head->ele;
        for(int k=0;k<2;k++)
        {
            if(k==0)
            {
                while(temp!=NULL)
                {
                    if(head==NULL)
                    temp=NULL;
                    else
                    {
                        temp=head->ele;
                        temp1=temp;
                        head=dequeue(head);
                        if(temp->ele==f)
                        {
                            f1=temp;
                            f2=1;
                        }
                        if(temp->left!=NULL)
                        {
                            if(temp->left->ele==f)
                            {
                                f1=temp->left;
                                f2=1;
                            }
                            head=enqueue(temp->left,head);

                        }
                        if(temp->right!=NULL)
                        {
                            if(temp->right->ele==f)
                            {
                                f1=temp->right;
                                f2=1;
                            }
                            head=enqueue(temp->right,head);
                        }
                    }
                }
            }
            else
            {
                if(f2==0)
                    break;
                head=enqueue(nn,head);
                temp=head->ele;
                f=temp1->ele;
                while(temp!=NULL)
                {
                    if(head==NULL)
                    temp=NULL;
                    else
                    {
                        temp=head->ele;
                        head=dequeue(head);
                        if(temp->left!=NULL)
                        {
                            if(temp->left->ele==f)
                            {
                                temp->left=NULL;
                                break;
                                f2=1;
                            }
                            head=enqueue(temp->left,head);

                        }
                        if(temp->right!=NULL)
                        {
                            if(temp->right->ele==f)
                            {
                                temp->right=NULL;
                                break;
                                f2=1;
                            }
                            head=enqueue(temp->right,head);
                        }
                    }
                }
            }
        }
        if(f2==0)
            printf("Element Not found\n");
        }

        //replacing and deleting

        if(f2!=0)
        {
            f1->ele=temp1->ele;
        }
        return nn;

}
void main()
{
    struct tnode *head1=NULL,*nn,*temp,*n1;
    struct node *head=NULL;
    int s,c,d,f,opt;
    printf("\nenter size of tree:");
    scanf("%d",&s); //size of list or tree
    nn=(struct tnode*)malloc(sizeof(struct tnode));
    head1=nn;
    head=enqueue(nn,head);
    printf("\nEnter element:");
    scanf("%d",&nn->ele);
    nn->left=NULL;
    nn->right=NULL;
    if(s>1)
    {   c=0;
        while(c!=s-1)
        {
            temp=head->ele;
            head=dequeue(head);
            d=0;
            while(d!=2)
            {
                n1=(struct tnode*)malloc(sizeof(struct tnode));
                printf("\nEnter element:");
                scanf("%d",&n1->ele);
                if(temp->left==NULL)
                {
                temp->left=n1;
                n1->right=NULL;
                n1->left=NULL;
                head=enqueue(n1,head);
                c++;
                if(c==s-1)
                {
                    head=NULL;
                    break;
                }
                }
                else
                {
                    temp->right=n1;
                    n1->right=NULL;
                    n1->left=NULL;
                    head=enqueue(n1,head);
                    c++;
                    if(c==s-1)
                    {
                        head=NULL;
                        break;
                    }
                }
                d++;
            }
        }
    }
    do
    {
        printf("\n\nEnter\n\n1.add an element\n\n2.Remove an element\n\n3.Exit\n\n==>");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                head1=add(head1);
                print(head1);
                break;
            case 2:
                head1=del(head1);
                print(head1);
                break;
            case 3:
                printf("Thank u");
                break;
            default:
                printf("Enter valid option\n\n==>");
        }
    }
    while(opt!=3);

}

