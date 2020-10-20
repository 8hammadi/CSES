#include <bits/stdc++.h>
using namespace std;
bitset<9> grid[9],val=bitset<9>().set();
int c=0;char cs[49];
string s;
void dfs(int i,int j){
	int t=s.size();
	//cout<<s<<" "<<c<<endl;
	if(s.size()==48 and i==7 and j==1){c++;/*cout<<s<<"  "<<c<<endl*/;}
	if(s.size()<48 and (i!=7 or j!=1)){
		int n=i,m=j+1;
		if((cs[t]=='?' or cs[t]=='R'))
		if(!grid[n][m] ){
			if(grid[n][m+1])if(!grid[n-1][m] and !grid[n+1][m])goto ensias;
			grid[n][m]=1;
			s.push_back('R');
			dfs(n,m);
			s.erase(s.end()-1);
			grid[n][m]=0;
			ensias:;
			}
			n=i+1;m=j;
		if((cs[t]=='?' or cs[t]=='D'))
		if(!grid[n][m]){
			if(grid[n+1][m])if(!grid[n][m+1] and !grid[n][m-1])goto hola;
			grid[n][m]=1;
			s.push_back('D');
			dfs(n,m);
	 		s.erase(s.end()-1);
			grid[n][m]=0;
			hola:;
		}
		n=i;m=j-1;if((cs[t]=='?' or cs[t]=='L'))
		if(!grid[n][m]){
			if(grid[n][m-1])if(!grid[n-1][m] and !grid[n+1][m])goto ensa;
			s.push_back('L');
			grid[n][m]=1;
			dfs(n,m);
			s.erase(s.end()-1);
			grid[n][m]=0;
			ensa:;
		}
		n=i-1;m=j;if((cs[t]=='?' or cs[t]=='U'))
		if(!grid[n][m]){
			if(grid[n-1][m])if(!grid[n][m-1] and !grid[n][m+1])goto inpt;
			s.push_back('U');
			grid[n][m]=1;
			dfs(n,m);
			s.erase(s.end()-1);
			grid[n][m]=0;
			inpt:;
		}
	}}
int main(){
	grid[0]=grid[8]=bitset<9>().set();
	for(int jj=0;jj<9;jj++){
		grid[jj][0]=1;
		grid[jj][8]=1;
	}	
	grid[1][1]=1;
	//for(auto y:grid)cout<<y<<endl;
	//stringstream sca("??????R??????U??????????????????????????LD????D?");sca>>cs;
	scanf("%s",cs);
	dfs(1,1);
	return 0*printf("%d",c);}
