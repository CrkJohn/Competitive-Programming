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
#define INF 1e18
#define len(a) ((int)a.size())
 
 
const double  eps =  1e-9;
const int  MOD = 998244353; //1e9+7;
 
inline int mul(int a, int b) { return 1ll*a*b%MOD; }
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
 
 
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<string> vs;
 
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> ostream& operator<<(ostream& os, vector<T> v){os << "[ ";for(auto e : v) os << e << " ";return os << "]";}
template <typename T> ostream& operator<<(ostream& os, pair<T,T> p){os << "(" << p.fi << "," << p.se <<")";return os;}
 
const double PI = acos(-1); 
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
double distance(double x,double y, double x_,double y_){return  sqrt(pow(x-x_,2) + pow(y-y_,2));}
int isTriangle(int a, int b, int c){return (a+b>c && a+c>b && c+b>a);}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
 
 
struct edge{
    ll u , v ,w; 
    edge(ll U ,ll V ,ll W){
        u = U;
        v = V;
        w  = W;
    }
    bool operator <(const edge other)const {
        return w < other.w;
    }
};
 
 
 
vector<vpll> G;
vll ans;
ll n,m,k;
const int maxn = 2* 1e5 + 100;
int exist[maxn];
int nodeth =  1;
    
void dijkstra(ll s){
    int debug = 30;
    vll dis(nodeth+10);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    for(ll i = 0 ; i <=  nodeth; ++i) dis[i]=INF;  dis[s]=0;
    pq.push(pll(0, s));    
    while (!pq.empty()){
        pll par=pq.top(); pq.pop();
        ll d=par.fi , u=par.se;  
        if (d<dis[u]) continue;
        for( ll j = 0 ;  j <  len(G[u]) ; j++){
            pll v=G[u][j];
            if (dis[u]+v.se < dis[v.fi]){
                dis[v.fi]= dis[u] + v.se;
                pq.push(pll(dis[v.fi],v.fi));
            }
        }
    }
    for(ll i = s+1 ; i <= nodeth ; i++){
        if(dis[i]!=0  && dis[i]!=INF && s<i){
            ans.pb(dis[i]);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(0);
    cout << fixed;
#ifdef LOCAL
    in();
 //   err();
#endif
    cin >> n >> m >> k;
    vector<edge> edges;
    forn(i,m){
        ll u , v , w; 
        cin >> u >> v>> w;
        u--;
        v--;
        edges.pb(edge(u,v,w));
    }
    sort(all(edges));
    G.assign(n+1,vpll());
    cls(exist,0);
    map<int,int> idNode;
    nodeth = 1;
    forn(i,min(k,m)){
        edge m = edges[i];
        if(!idNode[m.v])idNode[m.v] = nodeth++; 
        if(!idNode[m.u])idNode[m.u] = nodeth++;
        G[idNode[m.u]].pb(pll(idNode[m.v],m.w));
        G[idNode[m.v]].pb(pll(idNode[m.u],m.w));
        exist[idNode[m.v]] = exist[idNode[m.u]] = 1;
    }
    ans.clear();
    for(ll i = 1 ; i <= nodeth ; ++i){
        //cerr << i << " dij " << endl;
    
        if(exist[i])dijkstra(i);
        //cerr << i << " after dij " << endl;
    
    }   
    sort(all(ans));
    //cout << ans << endl;
    cout << ans[k-1] << endl;
 
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 
 
 
