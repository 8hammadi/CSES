#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    multiset<pair<int, int>> f;
 
    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        f.insert(make_pair(a, b));
 
    }
    int cnt = 0; b = 0;
    for(auto e:f)
    {
        if(e.first >= b)
        {
            cnt++;
            b=e.second;
        }
        else
        {
            if(e.second < b)
            {
                b = e.second;
            }
        }
    }
    cout << cnt;
    return 0;
}
