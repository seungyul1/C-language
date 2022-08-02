#include <stdio.h>

void Swap(int *a, int *b);
void Print_Array(int arr[], int length);
int Partition(int arr[], int Start, int End);
void Quick_Sort(int arr[], int Start, int End);

int main(){
    int arr[] = {3,5,1,10,8,4,9,2,6,7};
    
    Quick_Sort(arr,0,9);    //시간복잡도 O(nlogn)
    Print_Array(arr,10);
    return 0;
}

void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void Print_Array(int arr[], int length){
    for(int i=0; i <length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Quick_Sort(int arr[], int Start, int End){
    int Pivot_pos;
    if(Start >= End) //원소개 1개이거나 없는 경우 아무것도 안함
        return;
    Pivot_pos = Partition(arr,Start,End);
    Quick_Sort(arr,Start,Pivot_pos-1); //작은 부분
    Quick_Sort(arr,Pivot_pos+1,End);   //큰 부분
}


int Partition(int arr[], int Start, int End){
    //int pivot = arr[(Start + End)/2];
    int pivot = arr[End];
    int position = Start; //현재 피벗보다 작은 값이 올 위치!

    for(int curr_arg=Start; curr_arg <= End; curr_arg++){
        if(arr[curr_arg] <= pivot){
            Swap(&arr[curr_arg], &arr[position]);
            position++;
        }
    }
    return position-1; //최종 피벗의 위치! -1해줘야함!!!!!
}