#include <cstdio>
#define a long long
main(){a n=10000;
scanf("%lld",&n);
for(a i=1;i<=n;i++)printf("%lld\n",(a)((i-1)*(i+4)*(i*i-3*i+4)*0.5));}
