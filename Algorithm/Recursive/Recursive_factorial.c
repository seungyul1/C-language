#include <stdio.h>
int Factorial(int num);

int main(){

    printf("%d\n",Factorial(5));
    return 0;
}

int Factorial(int num){
    if(num == 1){
        return 1;
    }
    return num * Factorial(num-1);
}