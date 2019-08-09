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
#define INF 3000000000000000007ll
#define len(a) ((int)a.size())


const double  eps =  1e-9;
const int  MOD = 1e9+7;

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


const int SZ = 1e6;

ll notp[SZ];
vector<ll> primes;
ll Bound;

void sieve(ll bound){
	ll i,j;
	Bound=bound+1;
	memset(notp,0,sizeof(notp));
	notp[0]=notp[1]=1;
	for(i=2; i<=Bound; i++) if(!notp[i]){
		for(j=i*i; j<=Bound; j+=i) notp[j]=1;
		primes.push_back(i);
	}
}


bool isp(ll x){
	if (x < 2)return false;
	for (int i = 2; i * i <= x; ++i)if (x % i == 0)return false;
	return true;
}

void des(ll n ){
    int i =  0;
    ll u = -1;
    vll ans;
    if(n==1){
        cout << "1337" << endl;
        return ;
    }
    while(i <len(primes)){
        if(isp(n)){
          ans.pb(n);
          break;
        }
        if(n%primes[i] == 0){
            ll mul = 1;
            while(n%primes[i] == 0){
                n/=primes[i];
                mul*=primes[i];
            }
            ans.pb(mul);
             
            i++;

        }else{
            i++;        
        }
        
    }
    if (len(ans) == 1){
        forn(i,ans[0])cout << '1';
        cout <<"337"<<endl;
    }
    else if(len(ans) == 2){
        forn(i,ans[0])cout << '1';
        forn(i,ans[1])cout << "33";
        cout << 7 << endl;
    }else if(len(ans) == 3){
        forn(i,ans[0])cout << '1';
        forn(i,ans[1])cout << "33";
        forn(i,ans[2])cout << '7';
        cout << endl;
    }else{
        int lon = len(ans);
        while(lon>3){
            ll last = ans.back();ans.pop_back();
            ll last2 = ans.back();ans.pop_back();
            ans.pb(last*last2);
        }
        forn(i,ans[0])cout << '1';
        forn(i,ans[1])cout << "33";
        forn(i,ans[2])cout << '7';
        cout << endl;

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
    int n = 1e5+10;
    sieve(n);
    int q;
    cin >> q;
    forn(qq,q){
        ll n; cin>> n;
        des(n);
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


