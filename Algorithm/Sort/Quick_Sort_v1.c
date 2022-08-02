//https://code-lab1.tistory.com/3?category=1213003
//https://starfish22.tistory.com/22
#include <stdio.h>

void Partition(int arr[], int Left, int Right);
void Swap(int *a, int *b);
void Print_Array(int arr[], int length);

int main(){
    //int arr[] = {5,1,6,3,4,2,7};
    int arr[] = {5,3,7,8,4,9,1,2};
    int length = sizeof(arr) / sizeof(int) ;
    
    Partition(arr,0,length-1);
    Print_Array(arr,length);

    return 0;
}

void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}
void Print_Array(int arr[], int length){
    for(int i=0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Partition(int arr[], int Left, int Right){
    int pivot = arr[(Left+Right)/2]; //idx
    int left = Left;
    int right = Right;
    
    do {
        while (arr[left] < pivot)   //클 때까지 반복
            left++;
        while (arr[right] > pivot)  //작을 때 까지 반복
            right--;
        if(left <= right){          //
            Swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    } while (left <= right);
    //Print_Array(arr,8);
    if(Left < right)
        Partition(arr,Left,right);
    if(Right > left)
        Partition(arr,left,Right);
}