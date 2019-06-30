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
const int MAXN = 2*1e3  + 50;

int vis[MAXN];

vvi g;


int bfs(int src){
    queue<int> q;
    q.push(src);
    memset(vis, 0, sizeof vis);
    vis[1] = 1;
    int solve = -1e9;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : g[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = vis[u] + 1;
                solve = max(solve,vis[v]);
            }
        }
    }
    return solve;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in();
#endif
    int   n,m;
    cin >> n >> m;
    g.assign(n+1,vi());
    forn(i,m){
        int u , v;
        cin >> u >> v;
        g[u].pb(v);
    }
    int solve = bfs(1);
    int r = 1;
    fore(i,1,n){
        if(!vis[i]){
            r = 0;
            //cerr << " i : " <<  i << endl;
            break; 
        }
    }
    if(!r || solve<0)cout << "=[" << endl;
    else{
        cout << "=] " << solve-1 << endl;
    }
    
    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;

} 


