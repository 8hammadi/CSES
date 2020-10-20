#include <cstdio>
int main(){
	long long n,i;
	scanf("%lld",&n);
	long long somme=n*(1+n);somme/=2;
	while(--n){
		scanf("%lld",&i);
		somme-=i;
	}printf("%lld",somme);
	return 0;
}
