#include <stdio.h>
#define MAX_SIZE 10001

int Factorial(int n);


int main() {
	int N, K;
	int sum1 = 1;
	int sum2 = 1;
	int sum3 = 1;
	int ans;
	scanf("%d %d",&N,&K);

	//ans = Factorial(N) / (Factorial(K) * Factorial(N-K));
	
	for(int i=1; i <= N; i++) {sum1 *= i;}
	for(int i=1; i <= K; i++) {sum2 *= i;}
	for(int i=1; i <= (N-K); i++) {sum3 *= i;}

	ans = sum1 / (sum2 * sum3);	
	
	
	printf("%d\n",ans);
	return 0;
}

int Factorial(int n){
	if(n == 1){
		return 1;
	}
	return n * Factorial(n-1);
}