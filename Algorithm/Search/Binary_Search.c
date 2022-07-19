#include <stdio.h>

int Binary_Search(int *parr, int length, int target);

int main() {

    int arr[] = {2,10,16,32,58,95,100,200,300};
    int index;
    index = Binary_Search(arr, sizeof(arr)/ sizeof(int),200);
    if(index == -1) {
        printf("검색 결과가 없습니다!\n");
    }
    else {
        printf("%d 번째 자리에 있습니다.\n",index);
    }

    return 0;
}

int Binary_Search(int *parr, int length, int target){
    int low = 0;
    int high = length-1; //index기반!
    int mid;

    while (low <= high){
        mid = (low + high) / 2;
        if(parr[mid] == target){
            return mid;
        }
        else if(parr[mid] > target){ //작은 경우 탐색범위를 왼쪽으로
            high = mid - 1;
        }
        else {                       //큰 경우 탐색범위를 오른쪽으로
            low = mid + 1;
        }
    }
    return -1; //검색실패!
}