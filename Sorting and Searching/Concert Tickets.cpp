#include <bits/stdc++.h>
using namespace std;
// lower_bound
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, t;
    cin >> n >> m;
    multiset<int> H;
    for(int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        H.insert(h);
    }
 
    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        t++;
        auto lower = H.lower_bound(t);
        if(lower == H.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            lower--;
            cout << *lower << "\n";
            H.erase(lower);
        }
    }
    return 0;
}
