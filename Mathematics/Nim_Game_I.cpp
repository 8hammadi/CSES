#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main(int argc, char const *argv[])
{
    int n, t,x,r;
    cin>>t;
    while(t--){
        cin>>n;r=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>x;r^=x;
        }
            cout<<(r?"first":"second")<<" ";
    }
    
    return 0;
}
