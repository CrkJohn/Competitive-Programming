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
int isTriangle(int a, int b, int c){return (a+b>c && a+c>b && c+b>a);}

struct point{
	double x,y;
	point(){x= y = 0.0;}
	point(double X ,double Y){
			x =  X;
			y = Y;
	}
    bool operator <(const point &other){
      if(fabs(x-other.x) > eps)return x<other.x;
      return y < other.y;
    }
    bool operator==(const point &a) const {
    	return fabs(x-a.x)<eps && fabs(y-a.y) <eps;
    }
    point operator+(const point &a) const {
        return point(x + a.x, y + a.y);
    }
    point operator-(const point &a) const {
        return point(x - a.x, y - a.y);
    }
    point operator/(const double val) const {
        return point(x / val, y / val);
    }
    point operator*(const double val) const {
        return point(x * val, y * val);
    }
};


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
    int c;
    cin >> c;
    vector<point> points(c);
    double ans  = -DBL_MAX;
    forn(i,c){
        cin >> points[i].x >> points[i].y;
        ans = max(ans, points[i].x +points[i].y);
    }
    //sort(all(points));
    cout << ans << endl;
 
 

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


