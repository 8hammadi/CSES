#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
 
    cin >> x;
    n--;
 
    long long sum = 0, max = x;
    if(x > 0)sum = x;
    while(n--)
    {
        cin >> x;
        if(sum + x < 0)
        {
            sum = 0;
            if(max<x)max=x;
        }
        else
        {
            sum += x;
        	if(max < sum)max = sum;
        }
    }
    cout << max;
    return 0;
}
