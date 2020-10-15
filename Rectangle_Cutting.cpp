#include <bits/stdc++.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b
using namespace  std;
int cut(int a, int b, vector<vector<int>> &dp)
{
	if(a==b)return 0;
	if(a==0 or b==0)return 0;
	if(a>b)return cut(b,a,dp);
    if(dp[a][b] == -1)
    {
        dp[a][b] = 2500000 ;
        for(int i = 1; i < a; i++)dp[a][b] = min(dp[a][b], 1+cut(i, b, dp) + cut(a - i, b , dp));
        for(int j = 1; j < b; j++)dp[a][b] = min(dp[a][b], 1+cut(a, j, dp) + cut(a, b -j , dp));
    	if(dp[a][b] == 2500000)dp[a][b]=0;
    }
    return dp[a][b];
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b,m;
    cin >> a >> b;m=max(a,b);
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
    cut(m,m,dp);
    cout << cut(a,b,dp);
    return 0;
}
