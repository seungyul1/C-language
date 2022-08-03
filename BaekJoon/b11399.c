#include <stdio.h>
void Quick_Sort(int arr[], int Left, int Right);
void Swap(int *a, int *b);

int main(){
    int N;
    int arr[1000];
    int tmp[1000] = {0};
    int sum;



    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    Quick_Sort(arr,0,N-1);


    for(int j=0; j<N; j++){
        if(j==0){
            tmp[j] = arr[j];
        }
        else 
            tmp[j] = arr[j] + tmp[j-1];
    }

    for(int z=0; z<N; z++){
        sum += tmp[z];
    }

    printf("%d\n",sum);
    return 0;
}
void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Quick_Sort(int arr[], int Left, int Right){
    int pivot = arr[(Left + Right)/2];
    int left = Left;
    int right = Right;

    do {
        while (arr[left] < pivot)   //크면 멈춤
            left++;
        while (arr[right] > pivot)  //작으면 멈춤
            right--;
        if(left <= right){
            Swap(&arr[left], &arr[right]);
            left++;
            right--;
        }  
    } while (left <= right);        //right가 left보다 작아지면 멈춤!

    if(right > Left)
        Quick_Sort(arr,Left,right);
    if(left < Right)
        Quick_Sort(arr,left,Right);
}