#include <stdio.h>

void Merge_Sort(int arr[],int left,int right);
void Merge(int arr[],int left, int mid, int right);
int temp[10];

int main() {
    int wscore[10] = {0};
    int kscore[10] = {0};
    int wsum = 0;
    int ksum = 0;

    for(int i=0; i<10; i++){
        scanf("%d",&wscore[i]);
    }
    for(int i=0; i<10; i++){
        scanf("%d",&kscore[i]);
    }
    Merge_Sort(wscore,0,9);
    Merge_Sort(kscore,0,9);

    for(int j=9; j>=7; j--){
        wsum += wscore[j];
        ksum += kscore[j];
    }

    printf("%d %d\n",wsum,ksum);

    return 0;
}

void Merge_Sort(int arr[],int left,int right){
    int mid = (left+right)/2;
    if(left<right){
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}
void Merge(int arr[],int left, int mid, int right){
    int l_idx = left;
    int r_idx = mid+1;
    int t_idx = left;

    while (l_idx <= mid && r_idx <= right){
        if(arr[l_idx] <= arr[r_idx]){
            temp[t_idx++] = arr[l_idx++];
            if(l_idx == mid+1){
                while (r_idx <= right)
                    temp[t_idx++] = arr[r_idx++];
            }
        }
        else {
            temp[t_idx++] = arr[r_idx++];
            if(r_idx == right+1){
                while (l_idx <= mid)
                    temp[t_idx++] = arr[l_idx++];
            }
        }
    }

    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }
}