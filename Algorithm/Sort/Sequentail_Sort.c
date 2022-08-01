//
#include <stdio.h>

void Sequential_Sort(int arr[], int n);
void SWAP(int *a, int *b);
void Print_Array(int *parr, int n);

int main() {

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};

    Sequential_Sort(arr, 10);

    return 0;
}

void Sequential_Sort(int arr[], int n){
    int tmp;
    Print_Array(arr, n);
    for(int i=0; i<n; i++){
        //비교
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                SWAP(&arr[i],&arr[j]);
                Print_Array(arr,n);
            }
        }
    }

}

void Print_Array(int *parr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",parr[i]);
    }
    printf("\n");
}

void SWAP(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}