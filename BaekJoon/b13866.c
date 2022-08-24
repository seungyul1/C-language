#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int min=0;
	int max=0;
	int other = 0;
	int num[4];
	int sum = 0;

	for(int i=0; i<4; i++){
		scanf("%d",&num[i]);
		sum += num[i];
	}
	max = min = num[0];

	for(int j=0; j<4; j++){
		if(num[j] <= min) {min = num[j];}
		else if(num[j] >= max) {max = num[j];}
	}

	printf("%d\n",abs((max+min)- (sum-(max+min)))); //{0,2,2,3}같은 경우 반례를 취해주어야 함!

	return 0;
}