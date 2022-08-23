#include <stdio.h>
#include <string.h>

int main() {
	char str[101];
	char tmp[101];
	int i=0;
	scanf("%s",str);
	for( i=0; i<strlen(str); i++){
		tmp[i] = str[(strlen(str)-1)-i];
	}
	tmp[i] = '\0';	//마지막에 널 추가!

	if(strcmp(str,tmp) == 0){
		printf("%d\n",1);
	}
	else 
		printf("%d\n",0);

	return 0;
}