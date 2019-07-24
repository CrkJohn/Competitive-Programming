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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


int k , f = 0 , n;
vi arr;

        

void kha(int i, int take,vi pos){
    if(len(pos) == k && i < n){
        return;
    }
    if(f)return;
    if(len(pos)==k && i ==n){
        cout << "YES" << endl;
        forn(i,len(pos)-1){
            cout << pos[i] << ' '; 
        }
        cout << pos[len(pos)-1] << endl;
        f = 1;
        return;
    }

    ll sum = 0;
   
    for(int cut = i ; cut < n && !f; ++cut){
    //fore(cut,i,n-1){
        sum+=arr[cut];
        if(sum%2 != 0){

            pos.pb(cut+1);
            kha(cut+1,take+1,pos);
            //cout << sum << " " << cut+1 << " " << take+1  << endl; 
            
            pos.pop_back();
        }
    }
    return;
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
    int q;
    cin >> q;
    forn(qq,q){
        cin >> n >> k;
        arr.clear();
        arr.resize(n);
        forn(i,n){
            cin >> arr[i];
        }
        /*vi a;
        f  = 0;
        int take = 0;
        kha(0,0,a);
        if(!f)cout << "NO" << endl;
        */
        int pos = n/k;
        


    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


