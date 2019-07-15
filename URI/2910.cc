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
#define INF  1e12
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


struct edge {
    ll u , l , c;
    edge(ll U, ll L ,ll C){
        u = U;
        l = L;
        c = C;
    }
    bool operator <(const edge &o)const {
        if (l == o.l)
            return c > o.c;
        return l > o.l;
    }
};

ostream& operator<<(ostream& os, edge e) {
    os << "[ u :" << e.u << " l : " << e.l << " c:  " << e.c;
    return os << "]";
}


const int SZ = 1e5 + 100;


int isBest(const edge &a, const edge &b) {
  if (b < a) return 1;
  if (a < b) return -1; // greater
  return 0;
}

vector< vector<edge> > nodes;
vector<edge> best;

void dijkstra(int n){
    priority_queue<edge, vector<edge>> pq;
    forn(i,n+1)best.pb(edge(i,INF,INF)); 
    best[1] = edge(1,0,0);
    pq.push(edge(1,0,0));
    while (!pq.empty()){
        edge src=pq.top(); pq.pop();
        if (isBest(src,best[src.u])==1) continue;
        for(edge v : nodes[src.u]){
            edge nw = {v.u, src.l + v.l, v.c};
            if ( isBest(nw,best[v.u]) == -1){
                best[v.u]= nw;
                pq.push(nw);
            }
        }
    }

    ll ans = 0;
    fore(i,1,n){
        ans+=best[i].c;
    }
    cout << ans << endl;

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
    //out(test1);
#endif  
    int n,m;
    cin >>n >> m;
    nodes.assign(n+1,vector<edge>());
    forn(i,m){
        ll u,v,l,c;
        cin >> u >> v >> l >> c;
        nodes[u].pb(edge(v,l,c));
        nodes[v].pb(edge(u,l,c));    
    }
    dijkstra(n);
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


