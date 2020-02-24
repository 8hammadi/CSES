#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int T[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>T[i];
    }
    
    sort(T,T+n);
    long long cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=abs(T[i]-T[n/2]);
    }
    cout<<cost;
    return 0;
}
