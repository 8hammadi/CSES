#include <bits/stdc++.h>

using namespace std;
int n, q;

void update(vector<long long> &s, int pos, int val)
{
	pos+=n;
	s[pos] = val;
    while(pos/=2)
    {
        s[pos] = s[2 * pos] + s[2 * pos + 1];
    }
}
void get(vector<long long> &s, int a, int b)
{
	long long r=0;
    while (a < b)
    {
    	if(a%2)r+=s[a++];
    	if(b%2)r+=s[--b];
        a /= 2;
        b /= 2;

    }
    cout << r << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    vector<long long> s(2 * n, 0);
    for(int i = 0; i <  n; i++)
    {
        int x;
        cin >> x;
        update(s, i, x);
    }
    while(q--)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 1)update(s, a - 1, b);
        else
            get(s, n+a - 1, n+b );
    }
    return 0;
}
