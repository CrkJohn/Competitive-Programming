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
#define in(x) freopen(#x".txt","r",stdin)
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
 
const int SZ =  1e7 + 20;
int notp[SZ];
vector<int> primes;
ll Bound;
 
void sieve(){
	ll i,j;
	Bound=10000000+1;
	memset(notp,0,sizeof(notp));
	notp[0]=notp[1]=1;
	for(i=2; i<=Bound; i++) if(!notp[i]){
		for(j=i*i; j<=Bound; j+=i) notp[j]=1;
		primes.push_back((ll)i);
    //    cerr << i << endl;
	}
}
 
 
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in(in);
   //err();
    out(o1);
#endif
    sieve();
    ll n;
    while(cin >> n){
        for(auto num : primes){
            if(num>n) {
                cout << -1  << endl;
                return 0;
            }
            if(!notp[n-num]){
                cout << num << " "<< n-num << endl; 
                return 0;
            }
        }
        cout << -1 << endl;
    } 
 
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}