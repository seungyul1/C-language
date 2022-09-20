#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int main() {
    int x;
    const int y = 51;
    char **str;

    scanf("%d",&x);
    str = (char **)malloc(sizeof(char *) * x);
    
    for(int i=0; i<x; i++){
        str[i] = (char *)malloc(sizeof(char) * y);
        scanf("%s",str[i]);
    }

    //qsort는 매개변수가 어떤 포인터인지 알 수 없음(void *로 캐스팅 되어 들어오기 때문에)
    //포인터에 원소의 크기(셋째 매개변수)의 배수를 더해 각 원소의 주소를 얻는다.
    qsort(str,x,sizeof(char *),compare);
    //또한 비교함수에는 배열 원소를 가리키는 포인터를 넘겨주는데
    //각 포인터 배열의 원소를 가르키는 포인터를 줌
    

    for(int j=0; j<x; j++){
        free(str[j]);
    }
    free(str);
    return 0;
}

//포인터 배열의 각 원소를 가르키는 포인터를 받음
int compare(const void *a, const void *b){
        return strcmp(*(char **)a,*(char **)b);

}