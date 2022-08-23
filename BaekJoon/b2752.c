#include <stdio.h>
void Merge(int arr[], int left, int mid, int right);
void Merge_Sort(int arr[], int left, int right);

int temp[3];

int main(){
    int arr[3] = {0,};
    for(int i=0; i<3; i++){
        scanf("%d",&arr[i]);
    }
    Merge_Sort(arr,0,2);

    for(int i=0; i<3; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

void Merge(int arr[], int left, int mid, int right){
    int left_idx = left;
    int right_idx = mid+1;
    int temp_idx = left;

    while (left_idx <= mid && right_idx <= right){
        if(arr[left_idx] <= arr[right_idx]){        //오른쪽이 더 크면
            temp[temp_idx++] = arr[left_idx++];     //왼쪽부터 채우기
            if(left_idx == mid+1){                  //왼쪽먼저 다 채웠다면    
                while (right_idx <= right)
                    temp[temp_idx++] = arr[right_idx++];
            }
        }
        else {                                      //왼쪽이 더 크면
            temp[temp_idx++] = arr[right_idx++];    //오른쪽부터 채우기
            if(right_idx == right+1){
                while (left_idx<=mid)
                    temp[temp_idx++] = arr[left_idx++];
            } 
        }
    }

    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }    
}
void Merge_Sort(int arr[], int left, int right){
    int mid = (left + right) /2 ;

    if(left<right){
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}