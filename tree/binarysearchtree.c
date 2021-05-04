#include <stdio.h>
#include <stdlib.h>
//created structure of tree
struct tree
{
    struct tree *left;
    int ele;
    struct tree *right;
};

//it stores address of parent and its child(being used while searching an element)
struct address
{
    struct tree *r;  //r stands for root(child)
    struct tree *p;  //p stands for parent
};

//below code is inorder transversal(since it we can print elements in ascending order, i named it output)
void output(struct tree *root)
{
    struct tree *parent;

    if (root != NULL)
    {

        output(root->left);
        printf("%d ", root->ele);
        output(root->right);
    }
}

//preorder transversal
void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->ele);
        preorder(root->left);
        preorder(root->right);
    }
}

//postorder transversal
void postorder(struct tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->ele);
    }
}

//code to insert a new element
struct tree *insert(struct tree *root)
{
    int element;
    printf("\nenter the element that you want to insert:");
    scanf("%d", &element);

    struct tree *newElement;
    newElement = (struct tree *)malloc(sizeof(struct tree));
    newElement->ele = element;
    newElement->left = NULL;
    newElement->right = NULL;

    struct tree *temp = root;   //it stores initial value of root(because we are going to change root value to transverse whole tree)

    if (root == NULL)
    {
        root = newElement;
        temp = newElement;
    }
    else
    {

        while (1)
        {
            
            if (root->ele > element)                //to add element smaller than the root
            {

                if (root->left != NULL)             //checking if left is NULL
                {

                    root = root->left;
                }
                else
                {
                    root->left = newElement;
                    break;
                }
            }
            else                                    //to add element greater than the root
            {
                if (root->right != NULL)            //checking if right is NULL
                {

                    root = root->right;
                }
                else
                {

                    root->right = newElement;
                    break;
                }
            }
        }
    }
    return temp;                                    //returning intial root value
}

//code to del element
void del(struct tree *root, struct tree *parent)
{   
    //root contains the address of the element that need to be deleted

    struct tree *temp, *realRoot;
    realRoot = root;                                //to store initial root value
    int flag = 0;
    if (root->left == NULL && root->right == NULL)  //if root doesnot have any child
    {
        if (parent->left == root)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    else if (root->left == NULL && root->right != NULL) //if root has only right child
    {
        temp = root;
        root = root->right;
        flag = 0;
        while (root->left != NULL)
        {
            temp = root;
            root = root->left;
            flag = 1;
        }
        if (flag == 0)
            temp->right = root->right;
        else
            temp->left = root->right;                   

        realRoot->ele = root->ele;                      //replacing root element with smallest element of right group to the root
    }
    else if (root->left != NULL)                        //if root has any one of the childs
    {
        temp = root;
        root = root->left;
        while (root->right != NULL)
        {
            temp = root;
            root = root->right;
            flag = 1;
        }
        if (flag == 0)
            temp->left = root->left;
        else
            temp->right = root->left;
        realRoot->ele = root->ele;                       //replacing root element with largest element of left group to root
    }
}

//code to find an element
struct address *find(struct tree *root, int element, struct tree *parent)
{
    
    struct address *adrs;
     adrs = (struct address *)malloc(sizeof(struct address));
    if (root != NULL && root->ele == element)
    {
        printf("\nElement found!!\n\n");
       
        adrs->r = root;
        adrs->p = parent;
        return adrs;
    }
    else if (root != NULL && root->ele > element)
    {
        parent = root;
        find(root->left, element, parent);
    }
    else if (root != NULL && root->ele < element)
    {
        parent = root;
        find(root->right, element, parent);
    }
    else
    {
        printf("\nelement not found!!\n\n");
        adrs->p = NULL;
        adrs->r = NULL;
        return adrs;
    }
}

void main()
{
    struct tree *root = NULL, *parent = NULL;
    struct address *adrs;
    int option, element;
    printf(" \nBINARY SEARCH TREE");
    do
    {
        printf("\n\nEnter\n\n1.Insert Element\n2.Delete Element\n3.Display Elements\n4.Parent\n5.Search an Element\n6.Exit\n\n===>");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            root = insert(root);
            break;
        case 2:

            printf("\nEnter the element that you want to delete:");
            scanf("%d", &element);

            if (root == NULL)
                printf("\n\nNO ELEMENTS found!!\n\n");

            else if (root->left == NULL && root->right == NULL && root->ele == element)
            {
                root = NULL;
                printf("\n\nNO ELEMENTS left!!");
            }

            else
            {
                adrs = find(root, element, parent);
                if(adrs->r!=NULL)
                del(adrs->r, adrs->p);
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("\n\nNO ELEMENTS found...Tree is Empty!!\n\n");
            }
            else
            {
                output(root);
                printf("\n\n");
                preorder(root);
                printf("\n\n");
                postorder(root);
            }
            break;
        case 4:
            printf("\n\nEnter element:");
            scanf("%d", &element);
            adrs = find(root, element, parent);
            if(root == NULL)
            printf("\nNO Elements found...TREE is Empty!!");
            else if (adrs->p == NULL && adrs->r == NULL)                //if element not found in the tree
            {
                printf("\n\nEnter valid element\n");
            }
            else
            {
                if (adrs->p == NULL)
                    printf("It has NO parent.");
                else
                    printf("Its parent is \"%d\"", adrs->p->ele);
            }
            break;
        case 5:
            printf("\n\nEnter element:");
            scanf("%d", &element);
            adrs = find(root, element, parent);
            if(root==NULL)
            printf("\nNO Elements found...TREE is Empty!!");
            else if (adrs->p == NULL && adrs->r == NULL)
            {
                printf("\nEnter valid element\n");
            }
            else
            {

                if (adrs->p == NULL)
                    printf("It is the ROOT of tree.");
                else
                {
                    if (adrs->p->right == adrs->r)
                    {
                        printf("\n\nElement is \"right\" child of \"%d\"", adrs->p->ele);
                    }
                    else
                    {

                        printf("\n\nElement is \"left\" child of \"%d\"", adrs->p->ele);
                    }
                }
            }

            break;
        default:
            break;
        }
    } while (option != 6);
}
