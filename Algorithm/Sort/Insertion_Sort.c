//https://code-lab1.tistory.com/22

#include <stdio.h>
void Print_Array(int *parr, int length);
void Insertion_Sort(int *parr, int length);

int main() {

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};
    Insertion_Sort(arr,sizeof(arr)/sizeof(int));
    Print_Array(arr, sizeof(arr)/sizeof(int));
    
    
    return 0;
}

void Insertion_Sort(int *parr, int length){
    int key;
    int i,j;
    for(i=1; i<length; i++){
        key = parr[i];
        
        for(j=i-1; j >= 0 && key <parr[j]; j--){   //key값이 더 클 때 까지 
            parr[j+1] = parr[j];
        }
        parr[j+1] = key;
    }
}

void Print_Array(int *parr, int length){
    for(int i=0; i<length; i++){
        printf("%d ",parr[i]);
    }
    printf("\n");
}