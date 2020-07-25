#include <bits/stdc++.h>

using namespace std;



int main(int argc, char const *argv[])
{
    int n, x, a;
    long long sum;
    cin >> n >> x;
    pair<int, int> T[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        T[i] = make_pair(a, i);
    }
    sort(T, T + n);
    if(n < 4)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int i , k, j, l, ii, jj, kk, ll, solved = 0;
    for(i = 0; i < n - 3; i++)
    {
        for(j = i + 1; j < n - 2; j++)
        {
            k = j + 1;
            l = n - 1;
            while(k < l)
            {

                sum = T[i].first + T[j].first + T[k].first+T[l].first;
                if(sum > x)l--;
                else if(sum < x)k++;
                else
                {
                    solved = 1;
                    ii = i;
                    jj = j;
                    kk = k;
                    ll=l;
                    break;
                }

            }
        }
    }

    if(solved)  cout << T[ii].second + 1 << " " << T[jj].second + 1 << " " << T[kk].second + 1<<" "<<T[ll].second+1;
    else
        cout << "IMPOSSIBLE";

    return 0;
}
