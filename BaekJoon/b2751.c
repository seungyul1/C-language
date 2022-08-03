#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 1000000

void Merge_Sort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);
void Print_Array(int arr[], int length);
int temp[MAX_ARRAY_SIZE];

int main() {
    int N;
    int *parr;

    scanf("%d",&N);
    parr = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        scanf("%d",&parr[i]);
    }
    Merge_Sort(parr,0,N-1);
    Print_Array(parr,N);

    free(parr);
    return 0;
}

void Print_Array(int arr[], int length){
    for(int i=0; i< length; i++){
        printf("%d\n",arr[i]);
    }
}


void Merge_Sort(int arr[], int left, int right){
    int mid = (left + right) / 2;

    if(left < right){
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}

void Merge(int arr[], int left, int mid, int right){
    int left_idx = left;
    int right_idx = mid+1;
    int temp_idx = left;

    while (left_idx <= mid && right_idx <= right){
        if(arr[left_idx] <= arr[right_idx]){
            temp[temp_idx++] = arr[left_idx++];
            if(left_idx == mid+1){
                while (right_idx <= right)
                    temp[temp_idx++] = arr[right_idx++];
            }
        }
        else {
            temp[temp_idx++] = arr[right_idx++];
            if(right_idx == right+1){
                while (left_idx <= mid)
                    temp[temp_idx++] = arr[left_idx++];  
            }
        }
    }
    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }    
}