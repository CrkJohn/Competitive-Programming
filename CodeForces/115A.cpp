#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)


using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


const int maxn = 2010;
int p[maxn],vis[maxn];



int ans;

vvi g;

void dfs(const int &u,int depth){
	vis[u] = 1;
	if(depth>ans)ans = depth;
	for(int v : g[u]){
			if(!vis[v]){
					dfs(v,depth+1);
			}
	}
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    //in();
    int n;
    cin >> n;
    for1(i,n){
				cin >> 	p[i];
		}
		g.assign(n+1,vi());
		for1(i,n){
        if(p[i]!=-1){
							g[p[i]].pb(i);
        }
		}
		ans  = 0;
		memset(vis,0,sizeof vis);
		for1(i,n){
				if(!vis[i] && p[i]==-1){
						dfs(i,1);
				}
		}
		cout << ans << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
