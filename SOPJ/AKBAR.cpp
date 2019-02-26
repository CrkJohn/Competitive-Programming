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
#define si(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pi64;
typedef double ld;

ostream & operator<< (ostream &out, const pii &c){
	out << "x =" << c.fi << ",y = " << c.se << ";";
    return out;
}



const int maxn = 1e6  + 10;

vvi g;
int vis[maxn], vis2[maxn];


// https://gist.github.com/paramsingh/81d728295e6bd01860a0

int bfs(int src , int depth){
    forn(i,maxn-1)vis2[i]  = -1;
    vis2[src] = 0;
    vis[src] = 1;
    queue<int> q;
    q.push(src);
		while(!q.empty()){
				int u =  q.front();q.pop();
				if(vis2[u]==depth)continue;

				for(int v : g[u]){
						if(vis[v] != 0 && vis2[v]==-1){
								return 1;
						}
						if(vis2[v] == -1 && vis2[u] + 1 <= depth ){
							  vis2[v] = vis2[u] + 1;
							  vis[v] = 1;
								q.push(v);
						}
				}
    }
    return 0;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
		in();
		int ntc;
		cin >> ntc;
		forn(ctn,ntc){
			 g.clear();
			 int n,r,m;
			 cin >> n >> r >> m;
			 g.assign(n+1,vi());
			 forn(i,r){
					int u , v;
					cin >> u >> v;
					u--;
					v--;
					g[u].pb(v);
					g[v].pb(u);
			 }
			 int continu = 0;
			 memset(vis,0,sizeof vis);
       forn(j,m){
					int node, depth;
					cin >> node >> depth;
					node--;
					if(vis[node]){
						continu = 1;
					}
					if(!continu){
						 vis[node] =1;
						 int v2 = bfs(node,depth);
						 if(v2 == 1){
									continu = 1;
						 }
					}
       }
			 if(continu)forn(i,n){
					if(vis[i]!=1){
							continu = 1;
							break;
					}
			 }
			 cout <<  ((continu == 1 ) ? "No" : "Yes" ) << endl;
		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
