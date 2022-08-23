//주어지는 수의 범위가 작고(상한이 낮고), 메모리가 적을 때 
//O(N)의 시간복잡도로 정렬할 수 있는 정렬 알고리즘
//stable 정렬, Not-in-place(count필요)
//가장 큰 원소에 영향을 받음
#include <stdio.h>
int *Counting_Sort_v1(int arr[], int size);
void Counting_Sort_v2(int arr[]);
void Print_array(int arr[], int length);
int main(){

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};
    int *parr;

    parr = Counting_Sort_v1(arr,10);    //length에 최대값전달
    Print_array(parr,10);

    return 0;
}

void Print_array(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int *Counting_Sort_v1(int arr[], int size){
    int count[11] = {0,};               //최대값 보다 하나 크게 (0포함)
    int target;
    static int sorted_array[11] = {0,}; //최대값 보다 하나 크게 (0포함)

    for(int i=0; i<10; i++){            //범위는 arr에 맞춰서 없으면 어차피 0
        count[arr[i]]++;                //arr배열을 순회하며 counting
    }
    for(int j=1; j<11; j++){           
        count[j] += count[j-1];         //누적 값 계산
    }
    for(int k=9; k >= 0; k--){          //k값의 범위도 arr을 넘지 않아야 해!
        target = arr[k];
        sorted_array[count[target]-1] = target;
        count[target]--; 
    }
    return sorted_array;
}
