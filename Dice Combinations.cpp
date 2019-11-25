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
#define mp make_pair
#define fi first
#define se second
#define pf(n) cout << n << endl
#define pfs(n) cout << n
#define ps() cout << " "
#define sf(n) cin >> n
#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define graph vector< vector<int> >
#define vs vector<string>
#define max(a,b) ((a<b)?b:a)
#define min(a,b) ((a>b)?b:a)
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
#define debug(T) for(auto k:T)cout<<k<<" ";cout<<endl
const int MAXN = 100005;
#define gc getchar
#define INF 1e9
#define in(x) cin>>x
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
#define N 1000000007
int sum(int T[],int i){
  int somme=0;
  range(j,1,min(i,7)){
    somme+=T[i-j];somme%=N;}return somme;
}
int main() {
    FAST
   //Home
   int n;in(n);
   int T[n+1];
   mmst(T,0);
range(i,1,n+1){
  T[i]=sum(T,i);
  if(i<7)T[i]++;
  }pfs(*(T+n));
  return 0;
}
