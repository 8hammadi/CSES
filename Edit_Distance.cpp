#include <bits/stdc++.h>
#define min(a,b) (a<b)?a:b

using namespace  std;

string a, b;
// dp[i][j] distance between a[:i+1]  b[:j+1]
int go(int i, int j, const int n, const int m, vector<vector<int>> &dp)
{
	if(i==n)return m-j;
	if(j==m)return n-i;

    if(a[i] == b[j])
    {
        if(dp[i][j] == -1)
            dp[i][j] = go(i + 1, j + 1, n, m, dp);
    }
    else
    {
        if(dp[i][j] == -1)
            dp[i][j] = min(min(go(i, j + 1, n, m, dp) + 1, go(i+1, j+1, n, m, dp) + 1),go(i+1,j,n,m,dp)+1);
    }
    return dp[i][j];
}
int main(int argc, char const *argv[])
{
    cin >> a >> b;

    int n = a.size(), m = b.size();
    // dp[i][j] size of a is i and size of b is j

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[0][0]==0;
    cout << go(0, 0, n, m,dp);
    return 0;
}
