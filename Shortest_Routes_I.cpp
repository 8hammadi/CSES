#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector < vector<pair<int, int>>> v(n);

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        v[a].push_back(make_pair(b, c));
    }
    typedef pair<long long, int> T;
    vector<long long> d(n, 1e18);
    priority_queue<T, vector<T>, greater<T>> q;

    for(q.push({0, 0}); !q.empty(); q.pop())
    {
        long long l = q.top().first;
        int i = q.top().second;
        if(d[i] <1e18)continue;
        d[i]=l;
        for(auto j: v[i])q.push({j.second + l, j.first});
    }
    for(auto e : d)cout << e << " ";
    return 0;
}