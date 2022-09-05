#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b);
int main(){ 
    char str[20000][51] = {0};
    char tmp[51] = {0}; //스왑을 위한 임시 저장 공간
    int N;

    scanf("%d",&N);
    for(int i=0; i<N; i++){ scanf("%s",str[i]);}

	/*
    //길이순 버블 정렬 (시간초과 ㅜㅜ)
    for(int i=0; i<=N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(strlen(str[j]) > strlen(str[j+1])){
                strcpy(tmp,str[j+1]);
                strcpy(str[j+1],str[j]);
                strcpy(str[j],tmp);
            }
            else if(strlen(str[j]) == strlen(str[j+1])){
                if (strcmp(str[j],str[j+1]) > 0){
                    strcpy(tmp,str[j+1]);
                    strcpy(str[j+1],str[j]);
                    strcpy(str[j],tmp);
                }
                
            }
        }
    }*/
	qsort(str, N, sizeof(str[0]), compare);








    for(int i=0; i<N; i++){
        if(strcmp(str[i],str[i+1])==0){continue;}
        else {printf("%s\n",str[i]);}
    }
}  

int compare(const void *a, const void *b){
	char *tmp;
	if(strlen((char *)a) > strlen((char *)b)){
		strcpy(tmp,a);
        strcpy(a,b);
        strcpy(b,tmp);
	}
}