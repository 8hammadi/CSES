#include <iostream>
#include <cmath>
using namespace std;
int main(){
	ios_base::sync_with_stdio(NULL);cin.tie(0);
	int n;cin>>n;
	int m,a,i,s;
	while(n--){
		cin>>m;a=0;s=(int)sqrt(m);
		for(i=1;i<=s;i++)if(!(m%i))a++;a*=2;
		if(m%s==0 and s*s==m)a--;
		cout<<a<<"\n";	
	}
	return 0;
}
