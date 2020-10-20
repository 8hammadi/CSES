#include <bits/stdc++.h>
using namespace std;
set<char> s;
multiset<char> ms;
vector<string> v;
string ss;
int coun=0;
void f(int i){
	if(i==1){coun++;ss.push_back(*ms.begin());v.push_back(ss);ss.erase(ss.end()-1);;return;}
	for(auto j:s){
		if(ms.count(j)){
			ms.erase(ms.find(j));
			ss.push_back(j);
			f(i-1);
			ss.erase(ss.end()-1);
			ms.insert(j);
		}
	}
}
int main(){
	char c[9];
	scanf("%s",c);
	int i=0;for(;c[i];i++){s.insert(c[i]);ms.insert(c[i]);}
	f(i);
	printf("%d\n",coun);
	for(auto x:v)cout<<x<<endl;
	return 0;}
