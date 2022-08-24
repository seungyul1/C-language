#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int arr[2][2];
	int max = 0;
	int row = 0;
	int col = 0;

	for(int i=0; i<2; i++)
		for(int j=0; j < 2; j++)
			scanf("%d",&arr[i][j]);

	max = arr[0][0];
	//최소값은 틀리다
	//최대값을 기준으로 양옆임!
	for(int i=0; i<2; i++) {
		for(int j=0; j < 2; j++) {
			if(max <= arr[i][j]){
				max = arr[i][j];
				row = i;
				col = j;
			}
		}
	}
	if(row == 0 && col == 0)
		printf("%d\n",arr[0][1] + arr[1][0]);
	else if((row == 0 && col == 1) || (row == 1 && col == 0))
		printf("%d\n",arr[0][0] + arr[1][1]);
	else if(row == 1 && col == 1)
		printf("%d\n",arr[1][0] + arr[0][1]);
	//printf("%d\n",min);
	//printf("%d %d\n",row,col);
	return 0;
}