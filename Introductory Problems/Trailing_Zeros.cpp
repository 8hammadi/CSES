#include <cstdio>
#include <cmath>
int main(){
	int n,tr=0;scanf("%d",&n);
	int N=log(n)/log(5);
	while(N--)tr+=n/pow(5,N+1);
	return 0*printf("%d",tr);}
