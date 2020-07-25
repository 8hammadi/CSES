//in the name of almighty Allah let's proceed
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pi; 
typedef pair <ll, pi> spi; 
typedef pair <pi, pi> dpi;
const ll mod = 1000000007;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
 
#define Home ifstream cin("input.txt");
/*                                                       
       __.....__        _..._              .--.                      
   .-''         '.    .'     '.            |__|                      
  /     .-''"'-.  `. .   .-.   .           .--.                      
 /     /________\   \|  '   '  |           |  |    __                
 |                  ||  |   |  |       _   |  | .:--.'.         _    
 \    .-------------'|  |   |  |     .' |  |  |/ |   \ |      .' |   
  \    '-.____...---.|  |   |  |    .   | /|  |`" __ | |     .   | / 
   `.             .' |  |   |  |  .'.'| |//|__| .'.''| |   .'.'| |// 
     `''-...... -'   |  |   |  |.'.'.-'  /     / /   | |_.'.'.-'  /  
                     |  |   |  |.'   \_.'      \ \._,\ '/.'   \_.'   
                     '--'   '--'                `--'  `"             
 
*/
int cnt=0;
struct Node 
{ 
	char key; 
	vector<Node *>child; 
};
typedef Node* NODE;
Node *newNode(char key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	return temp; 
} 
void inserer(char key,NODE *root){
	(*root)->child.pb(newNode(key));
}
int chercher(char key,NODE root){
	for(int i=0;i<(root)->child.size();i++)if((root)->child[i]->key==key)return i;
	return -1;
}
void inserer_string(string s,NODE *root){
	if(s.size()==0){
		((*root)->child).insert(((*root)->child).begin(),newNode('*'));
		return;}
	int c=chercher(s[0],(*root));
	if(c==-1){
		auto ro=(*root);
		for(int i=0;i<s.size();i++){
			ro->child.pb(newNode(s[i]));
			(ro)=*((ro)->child.end()-1);
		}
		ro->child.insert(ro->child.begin(),newNode('*'));
		return;
	}else{
		s.erase(s.begin());
		inserer_string(s,&((*root)->child[c]));
	}
}
NODE rootglobal;
void solve(string S,NODE root){
	//cout<<S<<endl;
	if(S.size()==0 and root->child[0]->key=='*')cnt++;
	if(S.size()!=0){
		if(root->child[0]->key=='*'){
			//NODE roo=rootglobal;
			solve(S,rootglobal);}
		int c=chercher(S[0],root);
		S.erase(S.begin());
		if(c!=-1)solve(S,root->child[c]);
	}
}
void afficher(NODE root){
	cout<<root->key<<":";
	for(auto k:root->child){
		afficher(k);
		cout<<":";
	}cout<<endl;
}
int main() 
{
	FAST ;
	Node *root = newNode('*');
	string S,s;cin>>S;
	int n;cin>>n;	
	while(n--){
		cin>>s;
		inserer_string(s,&root);
	}
	//afficher(rootglobal);
	rootglobal=root;
	solve(S,root);
	cout<<cnt;
	return 0;
}
