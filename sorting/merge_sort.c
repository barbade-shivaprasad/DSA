#include<stdio.h>

void merge(int a[],int f,int l){

        int size = l-f+1;
        int temp[size];
        int k=0;
        int mid = (f+l)/2;
        int i = f;
        int j = mid+1;
        while (i <= mid && j <= l)
        {
            if(a[i] < a[j])
            {
                temp[k] = a[i];
                i++;
                k++;
            }
            else{

                temp[k] = a[j];
                j++;
                k++;
            }
        }
        while (i<=mid)
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        while (j<=l)
        {
            temp[k] = a[j];
            j++;
            k++;
        }
        for(int m=0;m<size;m++){

            a[f] = temp[m];
            f++;
        }
        
        
        
}



void mergesort(int a[],int f,int l){

    int mid = (f+l)/2;
    if(f<l){

        mergesort(a,f,mid);
        mergesort(a,mid+1,l);
        merge(a,f,l);

    }

}
void main(){

    int a[5] = {6,3,2,0,1};
    mergesort(a,0,4);
    
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}
