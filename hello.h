#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


int compare(const void *a, const void *b){  //void형은 어떤 형의 주소값이라도 저장할 수 있다.
    int num1 = *(int *)a;
    int num2 = *(int *)b;   

    if(num1 > num2) {
        return 1;
    }
    else if (num1 < num2){
        return -1;
    }
    else 
        return 0;
}
