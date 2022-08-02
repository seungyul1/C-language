#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc

void Quick_Sort(int arr[], int Start, int End);
void Swap(int *a, int *b);
void Print_Array(int arr[], int length);

int main(){
	int N;
	int *ptr;

	scanf("%d",&N);
	ptr = (int *)malloc(sizeof(int) * N);

	for(int i=0; i<N; i++){
		scanf("%d",&ptr[i]);
	}

	Quick_Sort(ptr, 0, N-1);
	Print_Array(ptr, N);

	free(ptr);
	return 0;
}

void Print_Array(int arr[], int length){
    for(int i=0; i <length; i++){
        printf("%d\n", arr[i]);
    }
}
void Swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Quick_Sort(int arr[], int Start, int End){
	int pivot = arr[(Start+End)/2];
	int start = Start;
	int end = End;
	do {
		while (arr[start] < pivot){
			start++;
		}
		while (arr[end] > pivot){
			end--;
		}
		if(start<=end){
			Swap(&arr[start], &arr[end]);
			start++;
			end--;
		}
	} while(start <= end);
	
	if(Start < end)
		Quick_Sort(arr,Start,end);
	if(start < End)
		Quick_Sort(arr,start,End);
}