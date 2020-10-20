#include <bits/stdc++.h>
#define max(a,b) (a>b)?a:b
 
using namespace std;
 
vector<string> g(1000);
long int dp[1000][1000] = {0};
int ways(int i, int j)
{
    if(i < 0 || j < 0 )return 0;
    if(g[i][j] == '*')return 0;
    if(i == 0 and j == 0)return 1;
    if(g[i][j] == '.')
    {
    	dp[i][j]=(ways(i - 1, j) + ways(i, j - 1))%((long int)1e9+7);
    	g[i][j]='#';
        return dp[i][j];
    }
    if(g[i][j] == '#')return dp[i][j];
}
int main(int argc, char const *argv[])
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++)cin >> g[i];
 
    cout << ways(n - 1, n - 1);
 
    return 0;
}
