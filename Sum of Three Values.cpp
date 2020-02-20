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
    // for(auto e:T)cout<<e.first<<" "<<e.second<<endl;
    if(n < 3)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int i = 0, k = n - 1,j,ii,jj,kk,solved=0;
    while(i < k - 1 )
    {
        j = k - 1;
        i = 0;
        while(i < j)
        {
            sum = T[i].first + T[j].first + T[k].first;
            if(sum < x)i++;
            else if(sum > x)j--;
            else
            {
            	solved=1;
            	ii=i;jj=j;kk=k;
            	k=0;break;
            }
 
        }
        k--;
 
    }
    if(solved)  cout << T[ii].second+1 << " " << T[jj].second+1 << " " << T[kk].second+1;
    else 
    cout<<"IMPOSSIBLE";
 
    return 0;
}
