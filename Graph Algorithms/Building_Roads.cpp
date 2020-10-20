#include <bits/stdc++.h>
 
using namespace std;
 
class Graphe
{
public :
    int n, m;
    vector<int> * V;
    vector<int> C;
    int c = 0;
    bool *visited;
    Graphe()
    {
        cin >> n >> m;
        V = (vector<int> *)malloc(n * sizeof(vector<int>));
        visited = (bool *)malloc(n * sizeof(bool));
        memset(visited,0,sizeof(visited));
        for(int a, b, i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;b--;	
            V[a].push_back(b);
            V[b].push_back(a);
        }
 
    }
    void findC(int k)
    {
        for(auto i:V[k]){
        	if(!visited[i]){
        		visited[i]=1;
        		findC(i);
        	}
        }
 
    }
    void solve()
    {
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
            	findC(i);
                C.push_back(i);
                c++;
            }
        }
 
        cout << c-1 << endl;
        for(int i = 0; i < c - 1; i++)
        {
           cout << C[i]+1 << " " << C[i+1]+1 << endl;
}
    }
 
 
 
};
 
int main(int argc, char const *argv[])
{
    Graphe g = Graphe();
    // g.show();
    g.solve();
    return 0;
}
