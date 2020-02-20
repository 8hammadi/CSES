#include <bits/stdc++.h>
 
using namespace std;
int min(int a,int b){return	 (a<b)?a:b;}
class Graphe
{
public :
    int n, m;
    vector<int> *V;
    vector<int> C;
    int c = 0;
    bool *visited;
    int *last;
    bool solved = 0;
    vector<int> solution;
    Graphe()
    {
        cin >> n >> m;
        V = (vector<int> *)malloc(n * sizeof(vector<int>));
        visited = (bool *)malloc(n * sizeof(bool));
        last = (int *)malloc(n * sizeof(int));
        // last[n-1]=-1;
        for(int i = 0; i < n; i++)last[i] = i;
        memset(visited, 0, sizeof(visited));
        visited[0] = 1;
        for(int a, b, i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            V[a].push_back(b);
            V[b].push_back(a);
        }
 
    }
    void solve()
    {
  		vector<int> v={0},vv;
  		int i;
  		while(!v.empty() and !solved){
  			vv.clear();
  			for(auto e:v){
 
  				for(auto s:V[e]){
  					if(!visited[s]){
  						visited[s]=1;
  						vv.push_back(s);
  						// printf("last od %d is %d \n",s+1,e+1);
  						last[s]=e;
 
  					}
  				}
  			}
  			v=vv;
 
  		}
  		// if(last[n-1]!=-1)solved=1;
    }
     void toString(int k)
    {
 
        if(k == 0)
        {
            //cout<<1<<" ";
            solution.push_back(1);
        }
        else
        {
            toString(last[k]);
            // cout<<k+1<<" ";
            solution.push_back(k + 1);
        }
 
    }
 
};
 
int main(int argc, char const *argv[])
{
    Graphe g = Graphe();
 	g.solve();
 
 	if(g.visited[g.n-1]){
 		g.toString(g.n-1);
 		cout<<g.solution.size()<<endl;
 		for(auto e:g.solution)cout<<e<<" ";
 	}else
 	cout<<"IMPOSSIBLE";
    return 0;
}
