#include <bits/stdc++.h>
#define max(a,b) (a>b)?a:b
using namespace std;

vector<vector<int>> dp(1e5+1, vector<int>(101, -1));
bool ok(vector<int> coins, int x, int j)
{
    if(x == 0)return 1;
    if(x < 0)return 0;
    if(j < 0)return 0;
    if(dp[x][j] == -1)dp[x][j] = ok(coins, x - coins[j], j - 1) or ok(coins, x, j - 1);
    return dp[x][j];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    int sum = 0;
    for(auto &e : x)
    {
        cin >> e;
        sum += e;
    }
    vector<int> s;
    for(int i = 1; i <= sum; i++)
    {
        if(ok(x, i, n - 1))s.push_back(i);
    }
    cout<<s.size()<<"\n";
    for(auto e:s)cout<<e<<" ";
    return 0;
}
