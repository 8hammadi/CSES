#include <bits/stdc++.h>
 
using namespace std;
 
class Graphe
{
public :
    int n, m;
    vector<int> *V;
    int c = 0;
    bool *visited;
    int *color;
    bool solved = 1;
    vector<int> solution;
    Graphe()
    {
        cin >> n >> m;
        V = (vector<int> *)malloc(n * sizeof(vector<int>));
        visited = (bool *)malloc(n * sizeof(bool));
        color = (int *)malloc(n * sizeof(int));
        memset(visited, 0, sizeof(visited));
        for(int a, b, i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            V[a].push_back(b);
            V[b].push_back(a);
        }
 
    }
    void C(int i)
    {
 
        vector<int> v = {i}, vv;
        int co = 1;
        color[i] = co;
        while(!v.empty() && solved)
        {
            vv.clear();
            co++;
            co %= 2;
            for(auto e : v)
                for(auto s : V[e])
                {
                	if(!visited[s])
                    {
                        visited[s] = 1;
                        vv.push_back(s);
                        color[s] = co;
                    }else if(color[s]!=co) {
                    	
                    	solved=0;
                    	break;
                    }
                }
            v = vv;
        }
 
    }
    void solve()
    {
        for(int i=0;i<n;i++){
        	if(!visited[i])
        	C(i);
        }
    }
	void show(){
        for(int i=0;i<n;i++)cout<<color[i]+1<<" ";
 
	}
 
};
 
int main(int argc, char const *argv[])
{
    Graphe g = Graphe();
    g.solve();
    if(g.solved)g.show();
    else cout<<"IMPOSSIBLE";
 
    return 0;
}
