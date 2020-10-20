#include <cstdio>
#include <cmath>
int main(){
	int t,a,b;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);int i=(2*a-b),j=(2*b-a);
		if(i%3==0 && j%3==0 && i>-1 && j>-1)printf("YES\n");else printf("NO\n");
	}
	return 0;}
