#include <cstdio>
#define valid(a,b) (a>-1 and b>-1 and a<n and b<m) 
using namespace std;
int grid[1002][1002];
int n,m;
void f(int i,int j){
	grid[i][j]=1;
	if(valid(i,j+1))
	if(!grid[i][j+1])f(i,j+1);
	if(valid(i,j-1))
	if(!grid[i][j-1])f(i,j-1);
	if(valid(i-1,j))
	if(!grid[i-1][j])f(i-1,j);
	if(valid(i+1,j))
	if(!grid[i+1][j])f(i+1,j);
}
int main(){
	int i,j,k,coun=0;scanf("%d%d",&n,&m);
	char s[1002];
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j!=m;j++)grid[i][j]=(s[j]=='#')?1:0;}
	for(i=0;i<n;i++)
		for(j=0;j!=m;j++){
			if(!grid[i][j]){
				coun++;f(i,j);
			}
		}
	return 0*printf("%d",coun);}
