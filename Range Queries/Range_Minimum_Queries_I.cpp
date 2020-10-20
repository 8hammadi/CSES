#include <bits/stdc++.h>
#define m(a,b) (a<b)?a:b
using namespace std;
main () 
{ 	int n,q,i,j;cin>>n>>q;
	int l=log2(n);
	int h[n][l+1];
	for(i=0;i<n;i++)cin>>h[i][0];
	for(j=1;j<=l;j++){
		for(i=0;i<n-(1<<j)+1;i++){
			h[i][j]=m(h[i][j-1],h[i+(1<<(j-1))][j-1]);
		}}
	while(q--){
		cin>>i>>j;i--;
		l=log2(--j-i+1);
		cout<<(m(h[i][l],h[j-(1<<l)+1][l]))<<endl;}} 
