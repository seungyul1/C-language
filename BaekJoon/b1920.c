#include <stdio.h>
#include <stdlib.h>

int Binary_Search(int *arr, int length, int target);
int compare(const void *a, const void *b);
int main() {
    int N,M;
    int *parr1;
    int *parr2;
    scanf("%d",&N);

    parr1 = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){ scanf("%d",&parr1[i]);}

    qsort(parr1,N,sizeof(int),compare);

    scanf("%d",&M);
    parr2 = (int *)malloc(sizeof(int)*M);

    for(int j=0; j<M; j++){ scanf("%d",&parr2[j]);}

    for(int z=0; z<M; z++){
        if(Binary_Search(parr1,N,parr2[z]) == 1) {
            printf("%d\n",1);
        }
        else {
            printf("%d\n",0);
        }
    }

    free(parr1);
    free(parr2);

    return 0;
}

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 > num2) { return 1;}
    else if(num1 < num2) { return -1; }
    else { return 0; }
}

int Binary_Search(int *arr, int length, int target){
    int start = 0;
    int end = length-1; //인덱스 기준
    int mid;

    while (start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == target){
            return 1;
        }
        else if(arr[mid] > target) //왼쪽 영역에 target이 있는 경우
            end = mid-1;
        else //오른쪽 영역에 target이 있는 경우
            start = mid+1;
    }

    return -1;//failed
}