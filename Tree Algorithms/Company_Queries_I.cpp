#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi p(n + 1);
    rep(i, 2, n + 1)cin >> p[i];
    p[1] = 1;
    int d = 1, i = 1;
    while(i < n)i *= 2, d++;
    vector<vi> boss(d, p);

    rep(i, 1, d)rep(j, 1, n+1)
    boss[i][j] = boss[i - 1][boss[i - 1][j]];

    int x, k;
    while(q--)
    {
        cin >> x >> k;
        rep(i, 0, d)
        if((k - 1) & (1 << i))
        {
            x = boss[i][x];
        }
        if(x == 1)
            cout << -1 << endl;
        else
        {

            x = p[x];

            cout << x << endl;
        }
    }
    return 0;
}