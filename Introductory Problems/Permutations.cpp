#include <cstdio>
#include <iostream> 
#include <cmath>
#define stable(e,i) (abs(e-T[i-1])!=1 && abs(e-T[i+1])!=1)
#define per(a,b) a^=b;b^=a;a^=b;
int main(){
	int n=6;
	scanf("%d",&n);
	if(n==1) return 0*printf("1");
	if(n<4) return 0*printf("NO SOLUTION");
	else{
		int T[n],i,j;
		for(i=0;i<n;i++)T[i]=i+1;
		for(i=0;i<n-1;i+=2){
			per(T[i],T[i+1])
		}
		for(i=1;i<n-2;i+=2)
			{
			per(T[i],T[i+1])
		}
		for(i=0;i<n;i++)printf("%d ",T[i]);
		}
	return 0;}
