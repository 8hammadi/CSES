#include <cstdio>
int main(){
	long long n;
	scanf("%lld",&n);
	while(n!=1){
		printf("%lld ",n);
		n=(n&1)?3*n+1:n/2;
	}printf("1");
	return 0;
} 
