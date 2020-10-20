#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int N,x;
	scanf("%d %d",&N,&x);
	int t;
	vector<pair<int,int>> v;
	for(int i=0;i<N;i++){
		scanf("%d",&t);
		v.push_back(make_pair(t,i+1));
}
	sort(v.begin(),v.end());
	int i=0,j=N-1,somme;
	while(i<j){
		somme=v[i].first+v[j].first;
		if(somme==x)return 0*printf("%d %d\n",v[i].second,v[j].second);
		else if(somme<x)i++;
		else j--;
	}
	printf("IMPOSSIBLE");return 0;
}
