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
#define NEXT(a,n) ((i+1)%n)

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

const int maxn = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in();
 //   err();
#endif
    bitset<maxn> prime;
    prime.set();
    prime[1] = 0;
    fore(i,2,maxn){
        if(prime[i]) {
            for(int j = i+i; j < maxn; j += i) {
                prime[j] = 0;
            }
        }
    }
    
    int n; 
    cin >> n;
    int degree[n];
    cls(degree,0);
    vpi g;
    forn(i,n){
        g.pb({i,NEXT(i,n)});
        degree[i]++;
        degree[NEXT(i,n)]++;
    }

    while(!prime[len(g)]){
        forn(i,n) {
            if(degree[i] == 2) {
                for(int j = i+2; j < n; j++) {
                    if(degree[j] == 2) {
                        g.pb({i, j});
                        degree[i]++;
                        degree[j]++;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    cout << len(g) << endl;
    for(auto tup  : g){
        cout << tup.fi+1 << " " << tup.se+1 << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


