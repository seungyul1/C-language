#include <stdio.h>

int str_length(char arr[]);

int main() {
	char str[] = {"HELLO MY NAME IS SYOH"};
	char *pstr = str;

	printf("%d \n",str_length(str));



	return 0;
}

int str_length(char arr[]){
	int len=0;
	while (arr[len]){
		len++;
	}
	return len;
}