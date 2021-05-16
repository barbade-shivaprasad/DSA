#include<stdio.h>

int size;

void dsf(int node,int arr[][size], int visited[]){

    if(visited[node] == 0){

        visited[node] = 1;

        printf("\n");
        printf(" %d => ",node);

        for(int i=0;i<size;i++){

            if(arr[node][i] == 1 && visited[i] == 0){

                printf("%d ",i);
                dsf(i,arr,visited);
            }
        }
    }
}



void main(){

    int arr[][6] = {{0,1,1,0,0,1},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,0,1},{0,1,1,0,0,1},{1,0,0,1,1,0}};

    size = 6;

    int visited[6];

    for(int i=0;i<size;i++){

        visited[i] = 0;
    }
        
    printf("\n\nFrom   TO\n");
    dsf(0,arr,visited);

    printf("All nodes are visited");
}
