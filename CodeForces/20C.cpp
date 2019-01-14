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
typedef long long i64;
typedef pair<i64, i64> pii;
typedef vector<i64> vi;
typedef vector<pii> vpi;
typedef vector<vpi> vvpi;
typedef vector<vi> vvi;

typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


vvpi g;
const int maxn =  100005;
i64 d[maxn];
i64 p[maxn];


void dijkstra(const int &node){
    priority_queue<pii, vpi , greater<pii> > pq;
    pq.push(mp(0,node));
    d[node] = 0;
    while(!pq.empty()){
        pii u = pq.top();pq.pop();
        if(d[u.se]<u.fi)continue;
        for(pii v : g[u.se]){
            i64 w_   = d[u.se] + v.fi;
//            cerr << u.se << " " << v.se << " " << v.fi << endl;
            if(w_<d[v.se]){
                d[v.se] = w_;
                p[v.se] = u.se;
                pq.push(mp(w_,v.se));
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;


//    in();
//    out();
    i64 n,m;
    cin >> n >> m;
    g.assign(n+2,vpi());
    forn(i,m){
        i64 u , v , w;
        cin >> u >> v >> w;
        g[u].pb(mp(w,v));
        g[v].pb(mp(w,u));
    }
    forn(i,n+1)d[i] = 1e18;
    forn(i,n+1)p[i] = -1;
    dijkstra(1);
    vi ans;

    if(d[n]==1e18){
        cout << -1 << endl;
    }else{
        int src = n;
        while(p[src]!=-1){

            ans.pb(src);
            src = p[src];
        }
        ans.pb(1);
        reverse(all(ans));
        forn(i,ans.size()-1){
            cout << ans[i] << " ";
        }
        cout << n <<endl;
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
