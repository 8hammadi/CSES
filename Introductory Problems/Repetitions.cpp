#include <cstdio>
#include <cstring>
using namespace std;
char c[1<<30];
int max(int a,int b){ return (a>b)?a:b;}
int Sub(char *s,int i,int f){
	if(s[i]=='\0')return 0;
	else if(s[i]==s[i+1])return Sub(s,i+1,f+1);
	else return max(f,Sub(s,i+1,1));
}
int main(){
	scanf("%s",c);
	printf("%d",Sub(c,0,1));
	return 0;
}
