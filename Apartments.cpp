#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,m,e,k,c=0,i,j=0;
	scanf("%d%d%d",&n,&m,&k);
	int A[m],B[n];i=n;
	while(i--){
		scanf("%d",B+i);
	}sort(B,B+n);i=m;
	while(i--){
		scanf("%d",A+i);
	}sort(A,A+m);i=0;
	while(i<n and j<m){
		if((long long) A[i]+k<B[j])i++;
		else if(A[i]-k>B[j])j++;
		else {i++;c++;j++;}
	}printf("%d",c);
	return 0;}
