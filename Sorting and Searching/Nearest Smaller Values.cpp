#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> t(n),s(n);
    cout<<"0 ";
    cin>>t[0];
    s[0]=-1;
 
    for(int i=1;i<n;i++)
    {
    	cin>>t[i];
    	int j=i-1,x=t[i-1];
    	while(x>=t[i] and j!=-1)
    	{
    		j=s[j];
    		x=t[j];
    	}
    	s[i]=j;
    	cout<<j+1<<" ";
    }
 
    return 0;
}
