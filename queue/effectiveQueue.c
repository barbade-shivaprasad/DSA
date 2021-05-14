#include <stdio.h>

int front = 0;
int rear = 0;


void display(int arr[],int size){

    int fr = front;      //so that actual front and rear values doesnt change
    int rr = rear;
    int flag = -1;

    if(arr[fr] == -1)
    printf("Empty..\n");

    
    while (arr[fr] != -1 )
    {
        if(fr == size)
        fr = 0;
            
        if(arr[fr] == arr[front])
        flag++;

        if(flag ==1)
        break;

        printf("%d ",arr[fr]);


        fr++;

            
    }
        
    
}

void enqueue(int arr[], int size)
{
    
    int ele;
    
    if(arr[rear] == -1){

        printf("\nEnter element : ");
        scanf("%d",&ele);

        arr[rear] = ele;
        printf("\nSuccess..\n");

        rear++;
    }
    else{

        printf("Queue is FULL\n");
    }

    if(rear == size)
    rear = 0;
    
    //To print top value

    if(arr[front] == -1)
    printf("NO TOP value");
    else
    printf("The TOP element is '%d'\n",arr[front]);
}


int dequeue(int arr[], int size)
{

    int temp;

    if(arr[front] == -1){

        printf("Empty\n");
    }
    else{

        temp = arr[front];
        
        arr[front] = -1;
        printf("\nSuccess..\n");

        front++;

        if(front == size)
        {
            front = 0;
        }
        printf("The dequeued element is '%d'\n",temp);
    }

    

    //To print top element

    if(arr[front] == -1)
    printf("Empty");
    else
    printf("The TOP element is '%d'\n",arr[front]);
    
}

void main()
{

    int size, opt, result;
    printf("Enter size of the queue:");
    scanf("%d", &size);

    // mark every element as -1...so that we can know NO ELEMENT is present
    int queue[size];

    for (int i = 0; i < size; i++)
    {

        queue[i] = -1;
    }

    do
    {
        printf("\nEnter\n\n1.Enqueue\n2.Dequeue\n3.Display Elements\n4.Exit\n\n==>");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:

            enqueue(queue, size);
            
            break;

        case 2:

            result = dequeue(queue, size);

            break;

        case 3:

            display(queue,size);
            
            break;

        default:
            break;
        }
    } while (opt != 4);
}
