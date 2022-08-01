#include <stdio.h>

int Binary_Search(int arr[], int low, int high, int target);
//int Binary_search(int arr[], int length, int target); //normal version

int main(){
    int arr[] = {2,10,16,32,58,95,100,200,300}; //반드시 정렬되어있어야함!
    int idx;
    idx = Binary_Search(arr, 0,sizeof(arr)/sizeof(int),77);
    if(idx == -1){
        printf("값이 배열안에 없습니다.\n");
        return 1;
    }
    else
        printf("%d번째 위치에 있습니다.\n",idx+1);
    return 0;
}


int Binary_Search(int arr[], int low, int high, int target){
    int mid;
    if(low > high)
        return -1; //탐색 실패 의미!
    mid = (high + low) /2;
    if(target == arr[mid]){
        return mid; //현재 위치 반환
    }
    else if(target > arr[mid]){ //오른쪽인 경우
        Binary_Search(arr, mid+1, high,target);
    }
    else if(target < arr[mid]){ //왼쪽인 경우
        Binary_Search(arr, low, mid-1,target);
    }
}






/*int Binary_search(int arr[], int length, int target){ //normal version
    int low = 0;
    int high = length;
    int mid = 0;

    while (low <= high){
        mid = (high + low) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if (arr[mid] > target){
            high = mid - 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
    }
    
    return -1;
}*/