#include <bits/stdc++.h>
#define max(a,b) (a>b)?a:b
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> hs(n), ss(n);
    for(auto &h : hs)cin >> h;
    for(auto &s : ss)cin >> s;
    vector<vector<int>> maxpages(n + 1, vector<int>(x + 1, 0));
    for(int i = 1; i < n + 1; i++)
    {
        for(int p = 0; p < x + 1; p++)
        {
            maxpages[i][p]=maxpages[i - 1][p];
            int r = p - hs[i-1];
            if(r >= 0)
            {
                maxpages[i][p] = max(ss[i-1] + maxpages[i - 1][r], maxpages[i][p]);
            }
        }
    }
    cout << maxpages[n][x];
    return 0;
}
