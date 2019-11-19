#include <cstdio>
int main(){
	int n,a,b,q;
	scanf("%d%d",&n,&q);long long int T[n];scanf("%lld",T);
	for(a=1;a<n;a++){
		scanf("%d",&b);T[a]=T[a-1]+b;
	}
	while(q--){
		scanf("%d%d",&a,&b);
		if(a==1)printf("%lld\n",T[b-1]);else
		printf("%lld\n",T[b-1]-T[a-2]);
	}
	return 0;
}
