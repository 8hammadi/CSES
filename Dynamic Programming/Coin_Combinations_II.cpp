#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    int mod = 1e9 + 7;
    vector<int> coins(n);
    for(auto &c : coins)cin >> c;

    vector<vector<int>> db(n + 1, vector<int>(target+1,0));

    db[0][0] = 1;

    for(int i = 1; i < n + 1; i++)
    {
        for(int x = 0; x < target + 1; x++)
        {
            db[i][x] = db[i - 1][x];
            int left = x - coins[i - 1];
            if(left >= 0)(db[i][x] += db[i][left]) %= mod;
        }
    }

    cout << db[n][target];
    return 0;
}
