#include <bits/stdc++.h>
#define max(a,b) (a>b)?a:b
using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> m; 
    int best = 0, cnt = 0,b=0;
    for(int i = 1; i < n+1; i++)
    {
        int c;
        cin >> c;
        b=max(b,m[c]);
        best=max(best,i-b);
        m[c] = i;
    }
    cout << best;
    return 0;


}
