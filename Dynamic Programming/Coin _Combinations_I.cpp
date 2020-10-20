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

    vector<int> db(target + 1, 0);

    db[0] = 1;

    for(int x = 1; x < target + 1; x++)
    {
        for(int i = 0; i < n ; i++)
        {
            int left = x - coins[i];
            if(left >= 0)(db[x] += db[left]) %= mod;
        }
    }

    cout << db[target];
    return 0;
}
