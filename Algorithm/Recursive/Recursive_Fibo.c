#include <stdio.h>

int Fibo(int num);

int main(){

    printf("%d\n", Fibo(4));
    return 0;
}

int Fibo(int num){
    if(num == 1)
        return 0;
    else if(num == 2){
        return 1;
    }
    else 
        return Fibo(num-1) + Fibo(num-2);
}