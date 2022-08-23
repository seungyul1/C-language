#include <stdio.h>
#include <stdlib.h>

void Merge_Sort(int arr[],int left, int right);
void Merge(int arr[],int left,int mid,int right);
void Print_Array(int arr[], int length);
int temp[1001];

int main(){
    int N;
    int *arr;
    int sum[1001] = {0};
    int ans=0;
    scanf("%d",&N);

    arr = (int *)malloc(sizeof(int)*N);
    for(int i=0; i<N;i++){
        scanf("%d",&arr[i]);
    }

    Merge_Sort(arr,0,N-1);  
    Print_Array(arr,N); 
    sum[0] = arr[0];
    for(int z=1; z<N; z++){
        sum[z] = sum[z-1] + arr[z];
    }
    for(int k=0; k<N; k++){
        ans += sum[k];
    }
    
    printf("%d\n",ans);
    free(arr);
    return 0;
}

void Merge_Sort(int arr[],int left, int right){
    int mid = (left + right) / 2;
    if(left<right){
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}

void Merge(int arr[],int left,int mid,int right){
    int l_idx = left;
    int r_idx = mid+1;
    int tmp_idx = left;

    while (l_idx <= mid && r_idx <= right){
        if(arr[l_idx] <= arr[r_idx]){
            temp[tmp_idx++] = arr[l_idx++];
            if(l_idx == mid + 1){
                while (r_idx<=right)
                    temp[tmp_idx++] = arr[r_idx++];
            }
        }
        else {
            temp[tmp_idx++] = arr[r_idx++];
            if(r_idx == right+1){
                while (l_idx<=mid)
                    temp[tmp_idx++] = arr[l_idx++];
              
            }
        }
    }

    for(int i=left; i <=right; i++){
        arr[i] = temp[i];
    }
}

void Print_Array(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}