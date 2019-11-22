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
#define N 1000007
bool ready[N];
int value[N];
vi coins;
int solve(int x) {if (x < 0) return INF;
    	if (x == 0) return 0;if (ready[x]) return value[x];
    	int best = INF;for (auto c : coins) 
    	{best = min(best, solve(x-c)+1);}
    value[x] = best;ready[x] = true;return best;}
int main() {
    FAST
   // Home
    mmst(ready,0);
    int n,e,x;
    in(n);in(x);
    range(i,0,n){
    	in(e);
    	coins.pb(e);}
    int c=solve(x);
    (c==INF)?pf(-1):pf(c);
    return 0;
}
