#include <stdio.h>
#include <stdlib.h>

int temp[10000000];

void Merge_Sort(int arr[], int Left, int Right);
void Merge(int arr[], int Left, int mid, int Right);
void Print_Array(int arr[], int length);

int main() {
    int N;
    int *p;
    scanf("%d",&N);

    p = (int *)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d",&p[i]);
    }

    Merge_Sort(p,0,N-1);
    Print_Array(p,N);

    free(p);
    return 0;
}

void Print_Array(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d\n",arr[i]);
    }
}

void Merge_Sort(int arr[], int Left, int Right){
    int mid = (Left + Right) / 2;
    
    if(Left < Right){
        Merge_Sort(arr,Left,mid);
        Merge_Sort(arr,mid+1,Right);
        Merge(arr,Left,mid,Right);
    }
}

void Merge(int arr[], int Left, int mid, int Right){
    int left_idx = Left;
    int right_idx = mid+1;
    int temp_idx = Left;
    while (left_idx <= mid && right_idx<=Right){
        if(arr[left_idx] <= arr[right_idx]){    //오른쪽이 더 크면
            temp[temp_idx++] = arr[left_idx++]; //작은것부터 채우기
            if(left_idx == mid+1){
                while (right_idx <=Right)
                    temp[temp_idx++] = arr[right_idx++];         
            }
        }
        else {
            temp[temp_idx++] = arr[right_idx++];
            if(right_idx == Right+1){
                while (left_idx <= mid)
                    temp[temp_idx++] = arr[left_idx++];      
            }
        
        }
    }
    for(int i=Left; i<=Right; i++){
        arr[i] = temp[i];
    }
}