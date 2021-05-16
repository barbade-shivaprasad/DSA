#include <stdio.h>
#include <stdlib.h>
void quicksort(int arr[], int first, int last)
{

    int i = first;
    int j = last;
    int pivot = arr[first];
    int temp;
    // printf("%d", pivot);
    if (i < j)
    {
        while (1)
        {

            if (arr[i] <= pivot)
            {
                // printf("yes\n");

                i++;
            }

            else if (arr[j] > pivot)
            {

                j--;
                // printf("no\n");
            }
            else
            {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }

            if (i > j)
            {
                temp = arr[j];
                arr[j] = pivot;
                arr[first] = temp;
                break;
            }
        }
        quicksort(arr, first, j-1);
        quicksort(arr, i, last);
    }
}

void main()
{

    int size, ele;
    printf("enter the size of array:");
    scanf("%d",&size);

    int *array;
    array = (int *)malloc(size * sizeof(int));
    

    for(int i=0;i<size;i++){

        printf("Enter element:");
        scanf("%d",&ele);

        array[i] = ele;
    }

    quicksort(array, 0, size-1);
    
    for (int in = 0; in < size; in++)
                {
                    printf("%d ", array[in]);
                }
}
