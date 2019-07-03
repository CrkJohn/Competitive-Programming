#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define len(a) ((int)a.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define cls(a,val) memset(a,val,sizeof a);

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

template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}
 
vector<pii> st;

const int MAXN = 1e4;

int tgt , vis[MAXN];


void dfs(int u){
    if (u == tgt){
       vis[tgt] = 1;
        return;
    }
    vis[u] = 1;
    forn(i,len(st)){
        pii v = st[i];
        if(u==i)continue;
        if(!vis[i] && ((v.fi < st[u].fi  && st[u].fi < v.se)|| (v.fi < st[u].se  && st[u].se < v.se) )){    
            dfs(i);
        }
    }
    return;
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
    int q,t,i,j;cin>> q;
    forn(query,q){
        cin  >> t >> i >> j;
        if(t==1){
            st.pb(pii(i,j));
        }else{
            i--; 
            j--;
            cls(vis,0);
            tgt = j;
            dfs(i);
            cout << (vis[tgt] ? "YES": "NO") << endl;
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


