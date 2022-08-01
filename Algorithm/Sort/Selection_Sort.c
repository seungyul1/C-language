//https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html
//https://ehpub.co.kr/2-3-%ec%84%a0%ed%83%9d-%ec%a0%95%eb%a0%acselection-sort/
 //순차정렬과 차이점은 맨 앞의 원소를 최소값이 있는 위치로 설정한 후에 
 //뒤에 원소들과 비교하여 더 작은 값을 발견하면 최소값의 위치를 바꾸는 거예요. 순차 정렬에서 원소를 교환했던 것과 다릅니다
#include <stdio.h>

void Selection_Sort(int arr[], int length);
void Print_Array(int arr[], int length);

int main() {

    int arr[10] = {9,4,3,10,5,8,7,6,2,1};
    int length = sizeof(arr) / sizeof(int) ;

    Selection_Sort(arr,length);
    Print_Array(arr,length);

    return 0;
}

void Selection_Sort(int arr[], int length) {
    int min;
    int min_idx;
    for(int i=0; i<length; i++){
        min = arr[i];
        min_idx = i;
        for(int j=i+1; j<length; j++){
            if(arr[j] < min) {
                min = arr[j];
                min_idx = j;
            }
        }
        arr[min_idx] = arr[i];
        arr[i] = min;
    }
}

void Print_Array(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
