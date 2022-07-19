#include <stdio.h>

void Print_Array(int *parr, int length);
void Bubble_Sort(int *parr, int length);

int main() {

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};

    Bubble_Sort(arr, sizeof(arr)/sizeof(int));

    return 0;
}

void Print_Array(int *parr, int length){
    for(int i=0; i<length; i++){
        printf("%d ",parr[i]);
    }
    printf("\n");
}


void Bubble_Sort(int *parr, int length){
    Print_Array(parr,length);
    int tmp;
    for(int i = 1; i <length; i++){ //i는 뒤에서 몇번째 원소에 최대값을 가져다 놓을지를 나타냄
        for(int j=0; j<length-i; j++){
            if(parr[j] > parr[j+1]){
                tmp = parr[j+1];
                parr[j+1] = parr[j];
                parr[j] = tmp;
                Print_Array(parr, length);
            }
        }                            
    }
}