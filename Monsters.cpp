#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int ii, jj, k, l;
vector<pair<int, int>> localPivots,localMonstres;
pair<int,int> B;
class Game;
class Monstres{
    public :
    vector<pair<int,int>> M;
    void print(){
        cout<<endl<<endl;
        for(auto m:M)cout<<m.first<<"  "<<m.second<<endl;
    }
    
    void nextMouve(Game &game);

};
class Game
{
public :
    int n, m, isSolved = 0, endOfMove = 0;
    string chemin;
    string game[1000];
    vector<pair<int, int>> Pivots;
    Monstres monstres;
    Game()
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> game[i];
            for(int j = 0; j < m; j++)
            {
                if(game[i][j] == 'A')Pivots.push_back(make_pair(i, j));
                if(game[i][j] == 'M')monstres.M.push_back(make_pair(i,j));

            }
        }
    }
    void print()
    {
        for(int i = 0; i < n; i++)cout << game[i] << endl;
    }
    void Solve()
    {
        //print();
        if(isSolved)return;
        localPivots.clear();
        monstres.nextMouve(*this);
        for(auto pivot : Pivots)
        {
            ii = pivot.first;
            jj = pivot.second;
            if(ii==0 or ii==n-1 or jj==0 or jj==m-1)
            {
                B=make_pair(ii,jj);
                isSolved = 1;

                return;
            }
            k = ii + 1;
            l = jj;
            if(isFreePoint(k, l))
            {
                localPivots.push_back(make_pair(k, l));
                game[k][l] = 'D';
            }

            k = ii - 1;
            l = jj;
            if(isFreePoint(k, l))
            {
                localPivots.push_back(make_pair(k, l));
                game[k][l] = 'U';
            }

            k = ii ;
            l = jj - 1;
            if(isFreePoint(k, l))
            {
                localPivots.push_back(make_pair(k, l));
                game[k][l] = 'L';
            }

            k = ii ;
            l = jj + 1;
            if(isFreePoint(k, l))
            {
                localPivots.push_back(make_pair(k, l));
                game[k][l] = 'R';
            }
        }



        Pivots = localPivots;
        if (Pivots.size() == 0)endOfMove = 1;
        else if(!isSolved )Solve();
    }

    int isFreePoint(int i, int j)
    {
        return 0 <= i and i< this->n and 0 <= j and j < this->m and (this->game[i][j] == '.' );
    }
    int isIncideGame(int i, int j)
    {
        return 0 <= i and i < this->n and 0 <= j and j < this->m and game[i][j]!='M' and game[i][j]=='.';
    }
    void getSolution()
    {
        if(game[B.first][B.second] != 'A')
        {
            chemin.push_back(game[B.first][B.second]);
            if(game[B.first][B.second] == 'R')B.second--;
            else if(game[B.first][B.second] == 'L')B.second++;
            else if(game[B.first][B.second] == 'U')B.first++;
            else if(game[B.first][B.second] == 'D')B.first--;
            getSolution();
        }
    }
};
void Monstres::nextMouve(Game &game){
    localMonstres.clear();
        for(auto m:M){
            ii=m.first;
            jj=m.second;
            k=ii+1;l=jj;
            if(game.isIncideGame(k,l)){
                game.game[k][l]='M';
                localMonstres.push_back(make_pair(k,l));
            }
            k=ii;l=jj+1;
            if(game.isIncideGame(k,l)){
                
                game.game[k][l]='M';
                localMonstres.push_back(make_pair(k,l));
            }
            k=ii;l=jj-1;
            if(game.isIncideGame(k,l)){
                game.game[k][l]='M';
                localMonstres.push_back(make_pair(k,l));
            }
            k=ii-1;l=jj; 
            if(game.isIncideGame(k,l)){
                game.game[k][l]='M';
                localMonstres.push_back(make_pair(k,l));
            }           
        }
       game.monstres.M=localMonstres;
    }
int main()
{
    Game A = Game();
    
    A.Solve();
 
    if(!A.isSolved)
    {
        cout << "NO";
    }
    else
    {
        A.getSolution();
        reverse(A.chemin.begin(), A.chemin.end());
        cout << "YES" << endl << A.chemin.size() << endl << A.chemin;
    }
    return 0;
}
