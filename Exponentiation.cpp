#include <cstdio>
int max=1e9+7;
long long c;
int pow(int a,int n){
	if(n==0) return 1;
	else {
		c=n/2;
		c=pow(a,c)%max;
		c=(c*c)%max;
		c=(n%2)?c*a:c;
		return c%max;
}}
int main(){
	int n;
	scanf("%d",&n);
	int a,b;
	while(n--){
		scanf("%d%d",&a,&b);
		a=pow(a,b);
		printf("%d\n",a);
	}
	return 0;
}
