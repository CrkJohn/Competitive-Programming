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
#define eps 1e-9
#define mod 1000000007
#define INf 3000000000000000007ll

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
typedef vector<string> vs;

template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}

const double PI = acos(-1); 
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
double distance(double x,double y, double x_,double y_){return  sqrt(pow(x-x_,2) + pow(y-y_,2));}

int isTriangle(int a, int b, int c){
    return (a+b>c && a+c>b && c+b>a);
}

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
    int a ,b, c;
    cin >> a >> b >>c;
    if(isTriangle(a,b,c)){
        cout << 0 << endl;
        return 0;
    } 
    int cnt = 0 ;
    //while (1){
        int ok = 1,tmp;
        if(a+b<=c){
            tmp = c-(a+b);
            a+=(tmp/2);
            b+=(tmp/2)+1;
            cnt+=tmp+1;
        }
        
        if(a+c<=b){
            tmp = b-(a+c);
            a+=(tmp/2)+1;
            c+=(tmp/2);
            cnt+=tmp+1;
        }
        if(c+b<=a){
            tmp = a-(c+b);
            c+=(tmp/2)+1;
            b+=(tmp/2);
            cnt+=tmp+1;
        }
       //if(isTriangle(a,b,c))break;
   // }
    cout << cnt << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


