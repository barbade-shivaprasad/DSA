#include<stdio.h>

int front = 0;
int rear = 0;
int size;

void enqueue(int arr[],int ele)
{

    

    if(arr[rear] == -1){

        arr[rear] = ele;
        rear++;
    }
    else{

        printf("Queue is FULL\n");
    }

    if(rear == size)
    rear = 0;

}


int dequeue(int arr[])
{

    int temp;

    
    if(arr[front] != -1){

        temp = arr[front];

        arr[front] = -1;
        

        front++;

        if(front == size)
        {
            front = 0;
        }
        
        return temp;
    }

}

int isempty(int arr[]){

    if(arr[front] == -1){

        return 1;
    }
    else{

        return 0;
    }
}

int in_queue(int arr[],int ele){

    for(int i=0;i<size;i++){

        if(arr[i] == ele)
        return 1;
    }
    return 0;
}

void bsf(int arr[][size] , int queue[] , int visited[]){

    while(!isempty(queue)){

        int temp = dequeue(queue);
        
        printf("\n");
        printf(" %d => ",temp);

        if(visited[temp] != 1){

            visited[temp] = 1;    
            for(int i=0;i<size;i++){

                if(arr[temp][i] == 1){

                    printf("%d ",i);
                    if(visited[i] == 0 && in_queue(queue,i) == 0)
                    enqueue(queue,i);
                    
                }
            }
        }

    }
    printf("\nEvery node is Visited");
    
}



void main(){

    int adj_matrix[][6] = {{0,1,1,0,0,1},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,0,1},{0,1,1,0,0,1},{1,0,0,1,1,0}};

    size = 6;

    int queue[36],visited[6];

    for(int i=0;i<size;i++){

        visited[i] = 0;
    }

    for(int i=0;i<36;i++){

        queue[i] = -1;
    }
        
    enqueue(queue,0);
        

    // printf("%d",sizeof(arr)/ (sizeof(int) * (sizeof (arr[0])) /sizeof(int)) );
    printf("\n\nFrom   TO\n");
    bsf(arr,queue,visited);
}


