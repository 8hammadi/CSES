#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for(auto &k : t)cin >> k;
    int i = 0, j = 0, sum = t[0], count = 0;
    while(i < n and j < n)
    {
        if(sum == x)
        {
            count++;
            if(j == n - 1)break;
            sum = sum - t[i] + t[j + 1];
            i++;
            j++;
        }
        else if(sum < x)
        {
            j++;
            sum+=t[j];
        }
        else
        {
        	sum-=t[i];
            i++;
        }
 
    }
 
    cout << count;
    return 0;
}
