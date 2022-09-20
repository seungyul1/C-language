#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int main(){
    int N;
    int sum = 0;
    int *arr = (int *)malloc(sizeof(int)*N);

    for(int i=0; i<N; i++) {scanf("%d",&arr[i]);}

    //오름차순 정렬
    qsort(arr,N,sizeof(int),compare);


    free(arr);
    return 0;
}

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 > num2) {return 1;}
    else if(num1 < num2) {return -1;}
    else return 0;
}