#include <stdio.h>


int Binary_search(int arr[], int length, int target);

int main(){
    int arr[] = {2,10,16,32,58,95,100,200,300}; //반드시 정렬되어있어야함!
    int idx;
    idx = Binary_search(arr, sizeof(arr)/sizeof(int), 16);
    if(idx == -1){
        printf("값이 배열안에 없습니다.\n");
        return 1;
    }
    else
        printf("%d번째 위치에 있습니다.\n",idx);
    return 0;
}

int Binary_search(int arr[], int length, int target){
    int low = 0;
    int high = length;
    int mid = 0;

    while (low <= high){
        mid = (high + low) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if (arr[mid] > target){
            low = mid + 1;
        }
        else if(arr[mid] < target){
            high = mid - 1;
        }
    }
    
    return -1;
}