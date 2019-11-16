#include <cstdio>
int main(){
	long long n,a,b,turns=0;
	scanf("%lld%lld",&n,&a);n--;
	while(n--){
		scanf("%lld",&b);
		if(a>b){
			turns+=a-b;
		}else a=b;}
	return 0*printf("%lld",turns);
}
