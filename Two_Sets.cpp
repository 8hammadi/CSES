#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
int main(){
	long long n=260443,i;
	scanf("%lld",&n);
	long long somme=n*(n+1)*0.5;
	if(somme%2)printf("NO");
	else{
		somme/=2;
		bitset<(int)1e6> s,v;
		for(i=n;i>0;i--){
			if(somme>=i){
				somme-=i;s[i-1]=2019;
			}else{
				v[i-1]=2020;
			}
		}
		printf("YES\n%d\n",(int)s.count());
		for(i=0;i<n;i++)if(s[i])printf("%lld ",i+1);
		printf("\n%d\n",(int)v.count());
		for(i=0;i<n;i++)if(v[i])printf("%lld ",i+1);
	}
	return 0;}
