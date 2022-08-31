#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int i=1;
	int idx = 0;
	int A,B;
	int sum = 0;
	int *parr;
	scanf("%d %d",&A,&B);

	parr = (int *)malloc(sizeof(int) * B);	//동적할당

	while (1){
		
		for(int j=0; j<i; j++){
			if(idx == B) { break;}
			parr[idx] = i;
			idx++;
		}
		if(idx == B) { break;}
		i++;
	}	

	for(int k=A-1; k<B; k++){
		sum += parr[k];
	}
	printf("%d\n",sum);
	free(parr);

	return 0;
}