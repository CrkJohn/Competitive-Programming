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
#define out(x) freopen(#x".txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define cls(a,val) memset(a,val,sizeof a)
#define INF  1e9;
#define len(a) ((int)a.size())



using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef double ld;

template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}

const double PI = acos(-1); 
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

const int LIM = 1e5 + 100;

int n, m, p[LIM], lo[LIM], num[LIM], dfscount, SCC;
int indeg[LIM];
bool vis[LIM];
set<int> tm1[LIM];

int ans = 0;
vvi AL;

int src , depht[LIM];

vector<int> graph[LIM]; 
vector<int> cycles[LIM]; 
  
// Function to mark the vertex with 
// different colors for different cycles 
void dfs_cycle(int u, int p, int color[],int mark[], int par[], int& cyclenumber){ 
    // already (completely) visited vertex. 
    if (color[u] == 2) { 
        return; 
    } 
    // seen vertex, but was not completely visited -> cycle detected. 
    // backtrack based on parents to find the complete cycle. 
    if (color[u] == 1){ 
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 
        int sizeCycle = 1;
        // backtrack the vertex which are 
        // in the current cycle thats found 
        while (cur != u) { 
            cur = par[cur]; 
            sizeCycle++;
            mark[cur] = cyclenumber; 
        } 
        //if(sizeCycle&1 == 1){
        ans = max(sizeCycle,ans);
        //}
        return; 
    } 
    par[u] = p;
    // partially visited. 
    color[u] = 1; 
    // simple dfs on graph 
    for (int v : AL[u]) { 
        // if it has not been visited previously 
        if (v == par[u]) { 
            continue; 
        } 
        dfs_cycle(v, u, color, mark, par, cyclenumber); 
    } 
    // completely visited. 
    color[u] = 2; 
} 
  
 
void printCycles(int edges, int mark[], int& cyclenumber) 
{ 
    cout << " entre" << endl;
    // push the edges that into the 
    // cycle adjacency list 
    for (int i = 1; i <= edges; i++) { 
        if (mark[i] != 0) 
            cycles[mark[i]].push_back(i); 
    } 
  
    // print all the vertex with same cycle 
    for (int i = 1; i <= cyclenumber; i++) { 
        // Print the i-th cycle 
        cout << "Cycle Number " << i << ": "; 
        for (int x : cycles[i]) 
            cout << x << " "; 
        cout << endl; 
    } 
} 



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in();
    err();
    out(out);
#endif
    int n , m ,t;
    cin >> t;
    while (t--){
        ans = 0;
        cin >> n >> m;
        
        AL.assign(n+2,vi());
        fore(i,1,m){
            int u , v;
            cin >> u >> v;
            AL[u].pb(v);
            AL[v].pb(u);
        }

        fore(i,1,n) num[i]=lo[i]=0, vis[i]=0;
        dfscount=1; SCC=0;
        int cyclenumber = 0; 
        int color[n+1]; 
        int par[n+1]; 
        // mark with unique numbers 
        int mark[n+1]; 
        fore(i,1,n){
            dfs_cycle(i, 0, color, mark, par, cyclenumber); 
        }
        //printCycles(edges, mark, cyclenumber); 
        cout << ans << endl;
    } 
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


