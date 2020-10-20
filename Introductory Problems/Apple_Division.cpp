#include <bits/stdc++.h>
using namespace std;
int y;int s[20];
long long int so(int c){
	if(c==0)return 0;
	y=log2(c);
	return s[y]+so(c-(1<<y));
}
int main(){
	int n,a;
	long long int somme=0;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		scanf("%d",&s[j]);
		somme+=s[j];
	}	
	long long int somme1,max=0,somme2=somme/2;
	for(register int i=1;i<(1<<n)-1;i++){
		somme1=so(i);
		if(somme1<=somme2 and somme1>max)max=somme1;
	}
	return 0*printf("%lld",somme-2*max);}
