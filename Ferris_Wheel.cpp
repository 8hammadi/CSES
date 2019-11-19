#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int n,x,m=0,i=0;
	cin>>n>>x;int w[n],j=n;;
	while(n--)cin>>w[n];
	sort(w,w+j);j--;
	while (i<j){
		if(w[j]+w[i]<=x){
			i++;j--;
		}else{
			j--;
		}m++;
	}
	if(i==j)m++;
	return 0*printf("%d",m);}
