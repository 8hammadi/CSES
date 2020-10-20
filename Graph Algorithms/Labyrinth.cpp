#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int ii,jj,k,l;
vector<pair<int,int>> localPivots;
pair<int,int> B;
class Game {
	public :
	 int n,m,isSolved=0,endOfMove=0;
	 string chemin;
	 string game[1000];
	 vector<pair<int,int>> Pivots;
	 Game(){
	 	cin>>n>>m;
	 	for(int i=0;i<n;i++){
	 		cin>>game[i];
	 		for(int j=0;j<m;j++){
	 			if(game[i][j]=='A')Pivots.push_back(make_pair(i,j));
	 			if(game[i][j]=='B')B=make_pair(i,j);
	 		}
	 	}
	 }
	 void print(){
	 	for(int i=0;i<n;i++)cout<<game[i] <<endl;
	 }
	void Solve(){

		if(isSolved)return;
		localPivots.clear();
		for(auto pivot:Pivots){
			ii=pivot.first;jj=pivot.second;
			if(ii==B.first and jj==B.second){
				isSolved=1;

				return;
			}
			k=ii+1;l=jj;
			if(isFreePoint(k,l)){
				localPivots.push_back(make_pair(k,l));
				game[k][l]='D';
			}

			k=ii-1;l=jj;
			if(isFreePoint(k,l)){
				localPivots.push_back(make_pair(k,l));
				game[k][l]='U';
			}

			k=ii ; l=jj-1;
			if(isFreePoint(k,l)){
				localPivots.push_back(make_pair(k,l));
				game[k][l]='L';
			}

			k=ii ; l=jj+1;
			if(isFreePoint(k,l)){
				localPivots.push_back(make_pair(k,l));
				game[k][l]='R';
			}
		}
		Pivots=localPivots;
		if (Pivots.size()==0)endOfMove=1;
		else if(!isSolved )Solve();
	}

	int isFreePoint(int i,int j){
		return 0<=i and i<this->n and 0<=j and j<this->m and (this->game[i][j]=='.' or this->game[i][j]=='B' );
	}
	void getSolution(){
		if(game[B.first][B.second]!='A'){
			chemin.push_back(game[B.first][B.second]);
			if(game[B.first][B.second]=='R')B.second--;
			else if(game[B.first][B.second]=='L')B.second++;
			else if(game[B.first][B.second]=='U')B.first++;
			else if(game[B.first][B.second]=='D')B.first--;
			getSolution();
		}
	}
};

int main(){
	Game A=Game();
	A.Solve();
	if(!A.isSolved){
		cout<<"NO";
	}
	else{
		A.getSolution();
		reverse(A.chemin.begin(),A.chemin.end());
		cout<<"YES"<<endl<<A.chemin.size()<<endl<<A.chemin;
	}
	return 0;
}
