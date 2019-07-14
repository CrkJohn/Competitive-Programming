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


struct node {
    int u, v , l , c;
    node(int U , int  V, int L ,int C){
        u = U;
        v = V;
        l = L;
        c = C;
    }
    bool operator <(const node &other)const {
        if (l== other.l)
            return c < other.c;
        return l < other.l;
    }
};
const int SZ = 1e5;
int r[SZ],p[SZ],sizeSet[SZ],componentes;

void makeSet(int N){
    int i;
    r[N];p[N];sizeSet[N];
    memset(r,0,sizeof r);
    memset(sizeSet,-1,sizeof sizeSet);
    forn(i,N+2)p[i]=i;
    componentes = N;
}
int findSet(int x){
       if (x!=p[x])p[x] = findSet(p[x]);
        return p[x];
}

bool isSameSet(int x,int y){
        return findSet(x)==findSet(y);
}

void unionSet(int xx,int yy){
    int x = findSet(xx);
    int y = findSet(yy);
    if (sizeSet[x]==-1) sizeSet[x] =1 ;
    if (sizeSet[y]==-1) sizeSet[y] = 1;
    if (!isSameSet(x,y)){
        componentes--;
        if (r[x] > r[y]){
            p[y] = x;
            sizeSet[x]+=sizeSet[y];
        }
        else{
            p[x] = p[y];
            sizeSet[y]+=sizeSet[x];
            if (r[x]==r[y])r[y]++;
        }
    }
    return;
}

vector<node> nodes;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in();
    err();
#endif  
    int n,m;
    cin >>n >> m;
    forn(i,m){
        int u,v,l,c;
        cin >> u >> v >> l >> c;
        nodes.pb(node(u,v,l,c));
    }
    sort(all(nodes));
    int mst = 0;
    makeSet(n);
    for(node nd : nodes){
        if(!isSameSet(nd.u,nd.v)){
            mst+=nd.c;
            unionSet(nd.u,nd.v);
        }
    }
    cout << mst << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


