#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	int T[N];
	for(int i=0;i<N;i++)scanf("%d",T+i);
	long long  somme=0,max=T[0];
	for(int i=0;i<N;i++){
		somme+=T[i];
		if(somme<0){
			somme=0;
		}else if(somme>max){
			max=somme;
		}
	}
	printf("%lld\n",max );return 0;
}
