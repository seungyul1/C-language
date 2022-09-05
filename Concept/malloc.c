#include <stdio.h>
#include <stdlib.h>
//2차원 배열의 동적할당
//방법1. 포인터 배열을 사용해서 2차원 배열 처럼 동작하는 배열을 만드는 방법
//방법2. 실제 2차원 배열 크기의 메모리를 할당한 뒤 2차원 배열 포인터로 참조하는 방법

int main(){
    int x,y;
    int **arr;

    printf("arr[x][y] 를 만들 것입니다.\n");
    scanf("%d %d",&x,&y);

    //int *형의 원소를 x개 가지는 1차원 배열 생성
    arr = (int **)malloc(sizeof(int *) * x); //각 원소가 포인터 이므로 arr은 이중포인터

    //각 배열 원소(포인터)에 1차원 배열 생성 후 주소 입력
    for(int i=0; i<x; i++){
        arr[i] = (int *)malloc(sizeof(int) * y);
    }

    printf("생성 완료!\n");

    for(int i=0; i<x; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}