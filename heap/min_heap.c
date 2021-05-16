#include <stdio.h>
int flag = 0;

void swap(int arr[], int pos1, int pos2)
{

    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;

    flag = 0;
}

void heapify(int arr[], int size, int i)
{

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //if both childs are present
    if (right < size)
    {

        if (arr[left] > arr[right])
        { //to identify min value

            if (arr[right] < arr[i]) //swapping min value with parent if min is less than parent
                swap(arr, i, right);
        }
        else
        {

            if (arr[left] < arr[i])
                swap(arr, i, left);
        }
    }

    //if single child is present
    else if (left < size)
    {

        if (arr[left] < arr[i]) //swapping min value with parent if min is less than parent
            swap(arr, i, right);
    }
}

void main()
{

    int size, ele;

    printf("\nEnter size: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {

        printf("Enter element : ");
        scanf("%d", &ele);

        arr[i] = ele;
    }

    while (flag == 0)
    {
        flag = 1;

        for (int i = size / 2; i >= 0; i--)
        {

            heapify(arr, size, i);
        }
    }

    for (int i = 0; i < size; i++)
    {

        printf("%d ", arr[i]);
    }
}
