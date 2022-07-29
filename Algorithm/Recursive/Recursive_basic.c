#include <stdio.h>

void Recursiv_call(int num);


int main(){

    Recursiv_call(3);
    return 0;
}

void Recursiv_call(int num){

    if(num <= 0){
        return;
    }
    printf("hello World!\n");
    Recursiv_call(num-1);
}