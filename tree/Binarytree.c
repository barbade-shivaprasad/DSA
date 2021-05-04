#include <stdio.h>
#include <stdlib.h>
//creating structure of tree
struct tnode
{
    struct tnode *left;
    int ele;
    struct tnode *right;
};

//creating structure of queue
struct node
{
    struct tnode *ele;
    struct node *next;
};

//code to enqueue
struct node *enqueue(struct tnode *e1, struct node *head)
{
    struct node *nn, *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->ele = e1;
    nn->next = NULL;
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}

//code to dequeue an element from queue
struct node *dequeue(struct node *head)
{
    struct node *temp;

    if (head == NULL)
        printf("\nFAILD\nNO ELEMENTS FOUND\n");
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
    }
    return head;
}

//code to print elements of tree
int print(struct tnode *nn)
{
    struct tnode *temp;
    struct node *head = NULL;
    if (nn == NULL)                             //if tree is empty
        printf("[]");
    else
    {
        head = enqueue(nn, head);
        printf("[");
        temp = head->ele;
        printf("%d ", temp->ele);               // printing first element
        while (temp != NULL)
        {
            if (head == NULL)
                temp = NULL;
            else
            {

                temp = head->ele;
                head = dequeue(head);
                if (temp->right == NULL && temp->left == NULL)
                    break;                      // since we have already printed 1st element so we r breaking
                if (temp->left != NULL)
                {
                    head = enqueue(temp->left, head);
                    printf("%d ", temp->left->ele);
                }
                if (temp->right != NULL)
                {
                    head = enqueue(temp->right, head);
                    printf("%d ", temp->right->ele);
                }
            }
        }
        printf("]");
    }

    return 0;
}

//code to add an element into the tree
struct tnode *add(struct tnode *nn)
{
    struct tnode *temp, *n1;
    struct node *head = NULL;
    if (nn == NULL)                                             //code to add element wn tree is empty
    {
        n1 = (struct tnode *)malloc(sizeof(struct tnode));
        printf("\nEnter the element that you want to add:");
        scanf("%d", &n1->ele);
        n1->left = NULL;
        n1->right = NULL;
        return n1;
    }
    else
    {
        head = enqueue(nn, head);
        temp = head->ele;
        while (temp != NULL)
        {
            if (head == NULL)
                temp = NULL;
            else
                temp = head->ele;
            head = dequeue(head);

            if (temp->left == NULL)
            {
                n1 = (struct tnode *)malloc(sizeof(struct tnode));
                printf("\nEnter the element that you want to add:");
                scanf("%d", &n1->ele);
                temp->left = n1;
                n1->left = NULL;
                n1->right = NULL;
                break;
            }
            else
                head = enqueue(temp->left, head);
            if (temp->right == NULL)
            {
                n1 = (struct tnode *)malloc(sizeof(struct tnode));
                printf("\nEnter the element that you want to add:");
                scanf("%d", &n1->ele);
                temp->right = n1;
                n1->left = NULL;
                n1->right = NULL;
                break;
            }
            else
            {
                head = enqueue(temp->right, head);
            }
        }
    }
    return nn;
}
struct tnode *del(struct tnode *nn) //function to delete desired element
{
    struct tnode *temp, *n1, *f1, *temp1;
    struct node *head = NULL;
    int f, f2;
    f2 = 0;
    printf("\n\nEnter the element that you want to delete:");
    scanf("%d", &f); //f is for storing element input from user
    temp1 = nn;      //temp1 is for transversing tree

    //code to del if only one element is present in tree
    if (nn->left == NULL && nn->right == NULL) //checking tree if it has child
    {
        printf("\n Every element got deleted...No element found");
        nn = NULL;
        return nn;
    }

    //transversing of tree starts to find element to delete
    else
    {
        head = enqueue(nn, head);
        temp = head->ele;

        //code to find element to be deleted and address of last element of tree

        while (temp != NULL)
        {
            if (head == NULL)                   //if queue is empty
                temp = NULL;
            else
            {
                temp = head->ele;
                temp1 = temp;
                head = dequeue(head);
                if (temp->ele == f)             //checks element matchs with input
                {
                    f1 = temp;                  //f1 is for storing address of element that we want to delete
                    f2 = 1;                     //f2 is used as flag..its value is when we find element
                }
                if (temp->left != NULL)         //to check element of left child
                {
                    if (temp->left->ele == f)
                    {
                        f1 = temp->left;
                        f2 = 1;
                    }
                    head = enqueue(temp->left, head);
                }
                if (temp->right != NULL)        //to check element of right
                {
                    if (temp->right->ele == f)
                    {
                        f1 = temp->right;
                        f2 = 1;
                    }
                    head = enqueue(temp->right, head);
                }
            }
        }

        //code to find the parent of last element and clearing the address where last element was there
        if (f2 != 0)
        {
            head = enqueue(nn, head);
            temp = head->ele;
            f = temp1->ele;                         //f contains last element
            while (temp != NULL)
            {
                if (head == NULL)
                    temp = NULL;
                else
                {
                    temp = head->ele;
                    head = dequeue(head);
                    if (temp->left != NULL)
                    {
                        if (temp->left->ele == f)
                        {
                            temp->left = NULL;
                            break;
                            f2 = 1;
                        }
                        head = enqueue(temp->left, head);
                    }
                    if (temp->right != NULL)
                    {
                        if (temp->right->ele == f)
                        {
                            temp->right = NULL;
                            break;
                            f2 = 1;
                        }
                        head = enqueue(temp->right, head);
                    }
                }
            }
        }

        else
            printf("\nElement Not found\n");
    }

    //replacing element with last element

    if (f2 != 0)
    {
        f1->ele = temp1->ele;
    }
    return nn;
}
void main()
{
    struct tnode *head1 = NULL, *nn, *temp, *n1;
    struct node *head = NULL;
    int opt; //you will know use of this variables as we go futher
    
    // below code is for giving options to user and calling respective functions
    do
    {
        printf("\n\nEnter\n\n1.add an element\n\n2.Remove an element\n\n3.Exit\n\n==>");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            head1 = add(head1); //function to add item in tree
            print(head1);       //function to print all elements of tree
            break;
        case 2:
            head1 = del(head1); //function to del item from tree
            print(head1);
            break;
        case 3:
            printf("Thank u");
            break;
        default:
            printf("\nEnter valid option\n\n==>");
        }
    } while (opt != 3);
}
