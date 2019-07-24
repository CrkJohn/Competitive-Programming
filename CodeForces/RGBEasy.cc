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
#define NEXT(n,m) (((int)n+1) %m)

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
    string rgb = "RGB";
    string rgb2 = "GBR";
    string rgb3 = "BRG";
    
    int q;
    cin >> q;
    forn(qq,q){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int id = 0, id1 = 0 , id2 = 0;
        int minimo = 1e9;
        int c1 = 0, c2 = 0 , c3 = 0;
        forn(j,n){
            if(s[j] != rgb[id]){
                 c1++;
            }
            if(s[j] != rgb2[id]){
                c2++;
            }
                
            if(s[j] != rgb3[id]){
                c3++;
            }
            id = NEXT(id,3);
            if(j>=k-1){  
                //cout << " j " << j << " " <<  s[j+1-k] << endl; 
                minimo = min(minimo,c1);
                minimo = min(minimo,c2);
                minimo = min(minimo,c3);
                if(s[j-k+1]!=rgb[id1]){
                    c1--;
                }
                if(s[j-k+1] != rgb2[id1]){
                    c2--;
                }
                if(s[j-k+1] != rgb3[id1]){
                    c3--;
                }     
                id1 = NEXT(id1,3);    
            }
        }
        //cout << " " << endl;
        //cout << c1 << " " << c2 << " " << c3 << " "<< i <<  endl;
        
        
        cout << minimo << endl;
    }
    

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


