#include <stdio.h>

void Selection_Sort(int arr[], int length);
void Print_Array(int arr[], int length);

int main() {

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};
    int length = sizeof(arr) / sizeof(int) ;

    Selection_Sort(arr,length);
    Print_Array(arr,length);

    return 0;
}

void Selection_Sort(int arr[], int length) {
    int min;
    int min_idx;
    for(int i=0; i<length; i++){
        min = arr[i];
        //min_idx = 0;
        for(int j=i+1; j<length; j++){
            if(arr[j] < min) {
                min = arr[j];
                min_idx = j;
            }
        }
        arr[min_idx] = arr[i];
        arr[i] = min;
    }
}

void Print_Array(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
