#include <stdio.h>


int main() {
	int L;
	int A,B,C,D;
	double tmp1, tmp2;
	int ans1, ans2;

	scanf("%d",&L);
	scanf("%d",&A);
	scanf("%d",&B);
	scanf("%d",&C);
	scanf("%d",&D);

	tmp1 = (double)A/C;
	tmp2 = (double)B/D;

	ans1 = tmp1+1.9;	//올림하기 1을 더해주는 이유는 계산은 0이지만 1일은 걸리기 때문
	ans2 = tmp2+1.9;	//올림하기
	
	ans1 -= 1;
	ans2 -= 1;
	if(ans1 >= ans2) { printf("%d\n",L-ans1);}
	else {printf("%d\n",L-ans2);}


	return 0;
}