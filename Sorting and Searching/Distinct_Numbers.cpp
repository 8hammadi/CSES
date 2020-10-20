#include <cstdio>
#include <set>
using namespace std;
int main(){
	set<int> s;int n,a;
	scanf("%d",&n);
	while(n--){scanf("%d",&a);s.insert(a);}
	return 0*printf("%d",(int)s.size());
}
