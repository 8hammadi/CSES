#include <bits/stdc++.h>
using namespace std;
int main () 
{ 	int n,e;cin>>n;int i=n;
	vector<pair<int ,bool>> T;
	while(i--){
		cin>>e;
		T.push_back(make_pair(e,1));
		cin>>e;
		T.push_back(make_pair(e,0));
	}
	sort(T.begin(),T.end());
	int max=0,c=1;
	while(i<2*n){
		(T[i].second)?++c:--c;
		if(c>max)max=c;i++;
	}
	cout<<max;
	return 0 ;
} 
