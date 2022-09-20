#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int main() {
    int N;
    scanf("%d",&N);

    //배열포인터 사용
    char (*str)[51] = (char (*)[51])malloc(sizeof(char) * N * 51);
    for(int i=0; i<N; i++){
        scanf("%s",str[i]);
    }

    qsort(str,N,sizeof(char)*51,compare);

    for(int i=0; i<N; i++){
        if(strcmp(str[i], str[i+1]) == 0){ continue;}
        else { printf("%s\n",str[i]);}
    }

    free(str);
    return 0;
}

int compare(const void *a, const void *b){
    if(strlen((char *)a) > strlen((char *)b)){
        return 1;
    }
    else if (strlen((char *)a) < strlen((char *)b)){
        return -1;
    }
    else 
        return strcmp((char *)a,(char *)b);
}


/*
qsort함수는 매개변수가 어떤 포인터인지 알 수 없으므로(void *로 캐스팅 되어 들어오기 때문에)
그 포인터에 원소의 크기(셋째 매개변수)의 배수를 더하여 각 원소의 주소를 얻습니다.
내가 셋째 매개변수를 어떤 값을 주는 가에 따라 배열 전체를 줄수 있음



*/