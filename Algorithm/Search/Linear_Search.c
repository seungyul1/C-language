#include <stdio.h>

int Linear_Search(int *parr, int length, int data);
//int Linear_Search(int arr[], int data);

int main () {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int index;

    index = Linear_Search(arr, sizeof(arr)/ sizeof(index), 3);
    if(index == 1) {
        printf("검색 실패");
    }
    else {
        printf("%d번째 자리에 있습니다. \n",index);
    }

    return 0;

}

//int Linear_Search(int arr[], int data){
int Linear_Search(int *parr,int length, int target){
    int idx;
    for(int i=0; i < length; i++) {
        if(parr[i] == target){
            return i;
        }
    }
    return 1;
}