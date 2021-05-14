#include<stdio.h>
#include<stdlib.h>

int ele;
int arr[5];
int front = 0;
int rear=0;

void enqueue()
{
    if(rear == 5)
    {
        printf("\nQueue IS FULL");
    }
    else
    {
        printf("\nenter the element: ");
        scanf("%d",&ele);
        arr[rear] = ele;
        rear++;
    }
}

void dequeue()
{
    if(rear == front)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        int temp = arr[0];
        for(int i=0;i < rear;i++){

            arr[i] = arr[i+1];
        }
        printf("The dequeued value is '%d'\n",temp);
        printf("The TOP value is '%d'\n",arr[0]);
        rear--;

    }
}

void display()
{
    printf("\n");
    for(int i=0; i<rear;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main()
{
    int choice;
    while(1)
    {
        printf("\nQUEUE\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nOTHERS TO EXIT\nENTER THE OPTION : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
            break;
        }
        
    }


}
