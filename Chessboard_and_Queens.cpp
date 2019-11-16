#include <cstdio>
#include <bitset>
using namespace std;
int c=0;
const int t=8;
bitset<t> column,diag1,diag2,occup[t];
void search(int i){
	if(i==t){c++;return;}
	else{
		for(int j=0;j<t;j++){
			if(column[j] || diag1[i+j] || diag2[i-j+t] || occup[i][j])continue;
			column[j]=diag1[i+j]=diag2[i-j+t]=1;
			search(i+1);
			column[j]=diag1[i+j]=diag2[i-j+t]=0;
		}
	}
}
int main(){
	char s[9];int i,j;
	for(i=0;i<t;i++){
		scanf("%s",s);
		for(j=0;s[j];j++){
		if(s[j]=='*')occup[i][j]=1;}}
	search(0);
	return 0*printf("%d",c);}
