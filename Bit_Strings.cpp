//WE CAN SOLVE THIS PROBLEM IN ONE LINE USING PYTHON
//print(2**int(input())%int(1e9+7))
#include <cstdio>
const int max=1e9+7;
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
	return 0*printf("%d",pow(2,n));
}
