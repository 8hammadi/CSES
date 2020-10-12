// Round Trip

#include <bits/stdc++.h>

#define gdb(x) //cout<<#x<<" "<<x<<endl;
#define deepgdb(v) //cout<<#v<<" : ";for(auto e:v)cout<<e<<" ";cout<<endl;
using namespace std;

class Graph
{

public:
    int n, m, a, b, A, B, O;
    vector<int> v[100005];
    bool visited[100005], solved = 0;
    int prec[100005] = {-1};


    Graph(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (auto &v : visited)v = 0;
        for (auto &e : prec)e = -1;
    }

    void getRoads()
    {
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    void visite(int a)
    {
        if (!visited[a] or !solved)
        {
            visited[a] = 1;

            for (auto b : v[a])
            {
                if (!visited[b])
                {
                    prec[b] = a;
                    visite(b);
                }
                else if (b != prec[a] && solved != 1)
                {

                    A = a;
                    B = b;
                    solved = 1;

                }
            }
        }
    }

    void go()
    {
        for (int i = 0; i < n; i++)
        {
            if (!solved)
            {
                O = i;
                visite(i);
            }
        }
    }

    vector<int> getSolution()
    {

        vector<int> sa = {}, sb = {}, s = {};

        while (prec[A] != -1)
        {
            sa.push_back(A);
            A = prec[A];
        }
        sa.push_back(O);

        while (prec[B] != -1)
        {
            sb.push_back(B);
            B = prec[B];
        }
        sb.push_back(O);

        reverse(sb.begin(), sb.end());
        reverse(sa.begin(), sa.end());
        deepgdb(sa)deepgdb(sb)

        a = 0;

        while(a < sa.size() && a < sb.size() && sa[a] == sb[a])a++;
        a--;


        for(int i = a; i < sa.size(); i++)s.push_back(sa[i]);
        for(int i = a; i < sb.size(); i++)s.push_back(sb[i]);

        return s;
    }
};

int main(int argc, char const *argv[])
{
    int n, m;

    cin >> n >> m;

    Graph g = Graph(n, m);

    g.getRoads();

    g.go();

    if (g.solved)
    {
        vector<int> s = g.getSolution();

        if(s.size() <= 3 || s[0] == s[1] || s[1] == s[2] )cout << "IMPOSSIBLE";
        else
        {
            cout << s.size()  << endl;
            for (auto e : s)cout << e + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
