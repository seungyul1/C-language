#include <stdio.h>

int main() {
	int C;
	int cnt = 0;
	int arr[1001] = {0};
	int sum = 0;
	float avg = 0.0f;
	int tmp = 0;

	scanf("%d",&C);
	for(int i=0; i < C; i++){
		scanf("%d",&arr[0]);
		sum = 0;
		cnt = 0;
		for(int j=0; j <arr[0]; j++){
			scanf("%d",&arr[j+1]);
			sum += arr[j+1];
		}
		avg = (float)sum/arr[0];
		for(int k=1; k <= arr[0]; k++){
			if(arr[k] > (int)avg) {cnt++;}
		}
		tmp = (int)(((float)cnt/arr[0]*100000)+0.5);	//소수점 6번째 자리에서 반올림하기 때문에 10^5을 곱해줌
		printf("%0.3f%%\n",(float)tmp/1000);    		//C언어에서는 반올림 함수가 없기 때문에 0.5를 더하고 정수형으로 형변환 
	}
	return 0;
}