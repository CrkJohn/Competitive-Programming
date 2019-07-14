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
#define INF  1e9
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

vector< pair<char,int> > gen(string a){
    vector< pair <char,int> > res;
    char def = a[0];    
    int cnt = 1;
    fore(i,1,len(a)-1){
        if(a[i] == def){
            cnt++;
        }else{
            res.pb(mp(def,cnt));
            def = a[i];
            cnt = 1;
        }
    }
    res.pb(mp(def,cnt));
    return res;
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
    int n;
    cin >> n;
    string s;
    getline(cin,s); 
    string t;    
    forn(i,n){
        getline(cin,s);
        getline(cin,t);
        auto sv = gen(s);
        auto st = gen(t);
        int ok = (len(sv) == len(st));
        for(int i = 0 ; i < len(st) && ok ; i++){ 
            ok &=(st[i].fi == sv[i].fi && st[i].se>=sv[i].se);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


