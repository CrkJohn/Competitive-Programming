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
    vi a(3);
    forn(i,3)cin >>a[i];
    sort(all(a));
    int d;
    cin >> d;
    int t = abs(a[1]-a[0]) , t2 = abs(a[2]-a[1]);
    int ans = 0;
    if(t<d)ans+=(d-t);
    else ans+=0;
    if(t2<d)ans+=(d-t2);
    else ans+=0;
    cout << ans << endl;
    


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


