#include <stdio.h>
#include <string.h>
//bubble정렬 이용!

int main() {
    char str[1001];
    char temp[1001][1001];
    char str2[1001]; //스왑을 위한 임시 
    int zz;
    int len;
    scanf("%s",str);
    len = strlen(str);
    //접미사 나누기!
    for(int i=0; i < len; i++){
        for(zz=0; zz < len; zz++){
            temp[i][zz-i] = str[zz];
        }
        temp[i][zz-i] = '\0';
    }

    for(int i=1; i<len; i++){
        for(int j=0; j<len-i; j++){
            if(strcmp(temp[j], temp[j+1]) > 0){      //앞이 더 크면 양수
                strcpy(str2, temp[j+1]);
                strcpy(temp[j+1], temp[j]);
                strcpy(temp[j], str2);
            }
        }
    }
    
    for(int j=0; j<len; j++){
        printf("%s\n", temp[j]);
    }
    return 0;
}