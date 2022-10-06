#include <stdio.h>

int Tiling(int x);
int d[1001];


int main(){
    int n;
    int ans;

    scanf("%d",&n);
    
    ans = Tiling(n);
    printf("%d\n",ans);

    return 0;
}


int Tiling(int x){
    if(x == 1) return 1;
    if(x == 2) return 3;
    if(d[x] != 0) return d[x];
    return d[x] = (Tiling(x-1) + 2*Tiling(x-2)) % 10007;
}