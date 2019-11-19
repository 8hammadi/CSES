#include <cstdio>
int p=1e9+7;
long long c;
int pow(int a,int n,int max){
	if(n==0) return 1;
	else {
		c=n/2;
		c=pow(a,c,max)%max;
		c=(c*c)%max;
		c=(n%2)?c*a:c;
		return c%max;
}}
int main(){
	int n;
	scanf("%d",&n);
	int a,b,c;
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		a=pow(a,pow(b,c,p-1),p);
		printf("%d\n",a);
	}
	return 0;
}
