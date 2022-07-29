#include <stdio.h>
void MergeSort(int arr[],int low, int high); //분할
int main() {


    return 0;
}


void MergeSort(int arr[],int low, int high){
    if(high == low) return; //같으면 1개의 원소를 의미
    int mid = (high + low)/2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1,high);                   
}