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

vvi g;

bool bfs(int src , int tgt){
    int vis[26];
    cls(vis,0);
    queue<int> q;
    q.push(src);
    vis[src]= 1;

    while(!q.empty()){
        int u = q.front();q.pop();
        cerr << "p  " << u << endl;
        if(u == tgt) return 1;
        for(auto v : g[u]){
            cerr << " child " << v << endl; 
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return 0;
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
#endif
    int n ,q;
    while(cin >> n >> q){
        char u,v;
        string lec;
        g.assign(26,vi());
        getline(cin,lec);
        forn(i,n){
            getline(cin,lec);
            g[lec[0]-'a'].pb(lec[2]-'a');
        //    g[lec[2]-'a'].pb(lec[0]-'a');
        } 
       
        forn(qq,q){
            string a, b;
            cin >> a >> b;
            bool ok = 1;
            if(len(a)!=len(b))ok = 0;
            for(int i = 0 ; i < len(a) && ok ; ++i){
                ok &= bfs(a[i]-'a',b[i]-'a');
            }
            cout <<  (ok ? "yes" : "no") << endl; 
            }
    }
    

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}