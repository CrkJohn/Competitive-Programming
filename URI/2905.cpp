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

const  int maxn = 1e4 + 10;
vll price;
vll times;
double memo[maxn][132][30];



double dp(ll i,ll t,ll tr) {
		if(i==len(price)) return 0;
		double ans = memo[i][t][tr];
		if (ans == 0) {
			double tmp = dp(i+1,times[i],1);
			double st = tmp == DBL_MAX ? DBL_MAX  : tmp + price[i];
			double ct = DBL_MAX;
			if(t < 120 && tr < 6 && tr > 0) {
				ct = dp(i+1,t+times[i],tr+1);
				if(ct != DBL_MAX){
					if(tr ==1) ct += price[i]*0.5;
					else ct += price[i]*0.25;
				}
			}
			ans = min(ct, st);
			memo[i][t][tr] = ans;
		}
		return ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(2);
    cout << fixed;
#ifdef LOCAL
    in();
    err();
#endif
    int n; 
    cin>> n;
    price.clear();
    times.clear();
    cls(memo,0);
    ll tn,m;
    forn(i,n){
        cin >> tn  >> m;
        times.pb(tn);
        price.pb(m);
    }
	cout << dp(0,0,0) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
