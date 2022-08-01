#include <stdio.h>
void Swap(int *a, int *b);
void Print_Array(int arr[], int length);

void Sequential_Sort(int arr[], int length);
void Selection_Sort(int arr[], int length); //자료의 크기가 클 때, 유리하지만 느리고 정렬의 안정성 만족 X
void Insertion_Sort(int arr[], int length);
void Bubble_Sort(int arr[], int length);

int main() {

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};
    int length = sizeof(arr) / sizeof(int);
    //Sequential_Sort(arr,length);
    //Selection_Sort(arr,length);
    //Insertion_Sort(arr,length);
    Bubble_Sort(arr,length);
    return 0;
}
void Swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void Print_Array(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Sequential_Sort(int arr[], int length){    //이중 for문 시간복잡도 O(n^2)
    int count=0;
    Print_Array(arr,length);
    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(arr[i] > arr[j]){
                Swap(&arr[i],&arr[j]);
                count++;
                Print_Array(arr,length);
            }
        }
    }
    printf("총 연산 횟수 : %d \n",count);
}

void Selection_Sort(int arr[], int length){ //이중 for문 시간복잡도 O(n^2)
    int min=0;                              //not-stable
    int min_idx;
    int count =0;
    Print_Array(arr,length);
    for(int i=0; i<length; i++){
        min = arr[i];
        min_idx = i;
        for(int j=i+1; j<length; j++){
            if(min > arr[j]){
                min = arr[j];
                min_idx = j;
            }
        }
        arr[min_idx] = arr[i];
        arr[i] = min;
        count++;
        Print_Array(arr,length);
    }
    printf("총 연산 횟수 : %d \n",count);
}

void Insertion_Sort(int arr[], int length){ //이중 for문 시간복잡도 O(n^2)
    int key;                                //Stable정렬 
    int j=0;
    int count=0;
    Print_Array(arr,length);
    for(int i=1; i<length; i++){
        key = arr[i];
        for(j=i-1; j>=0 && key<arr[j]; j--){
            arr[j+1] = arr[j];
            count++;
        }
        arr[j+1] = key;
        Print_Array(arr,length);
    }
    printf("총 연산 횟수 : %d \n",count);
}

void Bubble_Sort(int arr[], int length){    //이중 for문 시간복잡도 O(n^2)
    int count = 0;                          //stable정렬
    Print_Array(arr,length);
    for(int i=1; i<length; i++){
        for(int j=0; j<length-i; j++){
            if(arr[j] > arr[j+1]){
                Swap(&arr[j+1], &arr[j]);
                count++;
                Print_Array(arr,length);
            } 
        }
    }
    printf("총 연산 횟수 : %d \n",count);
}