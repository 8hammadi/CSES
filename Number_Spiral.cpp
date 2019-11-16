#include <cstdio>
int main(){
	long long n,m,a;
	scanf("%lld",&a);
	while(a--){
		scanf("%lld%lld",&n,&m);
		if(n>=m)(n%2)?printf("%lld\n",(n-1)*(n-1)+m):printf("%lld\n",n*n-m+1);
		else (m%2)?printf("%lld\n",m*m-n+1):printf("%lld\n",(m-1)*(m-1)+n);
	}
	return 0;}
