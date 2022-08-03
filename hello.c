#include <stdio.h>

void Merge_Sort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);
int temp[8];


int main() {


	return 0;
}

void Merge_Sort(int arr[], int left, int right){
	int mid = (left + right) / 2;
	if(left < right){
		Merge_Sort(arr,left,mid);
		Merge_Sort(arr,mid+1,right);
		Merge(arr,left,mid,right);
	}
}

void Merge(int arr[], int left, int mid, int right){
	int left_idx = left;		//왼쪽 시작 인덱스
	int right_idx = mid+1;		//오른쪽 시작 인덱스
	int temp_idx = left;		//비교 후 처음부터 채워넣어야 함으로! 

	//두 배열 비교 및 합병 시작
	while (left_idx <= mid && right_idx <= right){
		if(arr[left_idx] <= arr[right_idx]) {	//오른쪽값이 더 큰 경우
			temp[temp_idx++] = arr[left_idx++];
			if(left_idx == mid+1){
				while (right_idx <= right){
					temp[temp_idx++] = arr[right_idx++];
				}
			}
		}
		else {									//왼쪽값이 더 큰 경우
			temp[temp_idx++] = arr[right_idx++];
			if(right_idx == right+1){
				while (left_idx <= mid){
					temp[temp_idx++] = arr[left_idx++];
				}
			}
		}
	}
	for(int i=left; i<=right; i++)
		arr[i] = temp[i];
}