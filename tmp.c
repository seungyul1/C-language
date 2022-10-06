#include <stdio.h>
#include <stdlib.h>

int IsPrime(int data){
    if(data == 1) { return 0;}
    for(int i=2; i<data; i++){
        if(data %i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    //int arr[100];
    int cnt = 0;
    int n;
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        scanf("%d",&n);
        if(IsPrime(n)) { cnt++;}
    }

    printf("%d\n",cnt);
    return 0;
}