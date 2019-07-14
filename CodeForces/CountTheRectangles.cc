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

struct point{
	ll x,y;
	point(){x  =  y = .0;}
	point (ll X,ll Y){
			x =X;
			y =Y;
	}

    point operator -( point other)const{
        return point(other.x-x, other.y-y );
    }

};

struct seg{
    point x,y;
	seg(point X,point Y){
			x =X;
			y =Y;
	}
};



template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}

const double PI = acos(-1); 
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
double iiabs(point a){return sqrt(a.x*a.x+a.y*a.y);}
double dist(point a,point b){return iiabs(a-b);}

bool intsp(point  s0,point s1,point a){ return dist(s0,s1)==dist(s0,a)+dist(a,s1);}


bool isVertical( double x1, double y1,double  x2, double y2){
    return x2-x1==0;
}


int ccw(point a0, point a1, point a2){
	int result = (a2.x - a1.x)*(a0.y-a1.y) - (a2.y-a1.y)*(a0.x-a1.x);
	if (result < 0) return -1;
	if (result > 0) return 1;
	return 0;
}

bool intss(point a0,point a1,point b0,point b1){
  if(ccw(a0,a1,b0)>=0&&ccw(a0,a1,b1)<=0&&ccw(b0,b1,a0)<=0&&ccw(b0,b1,a1)>=0) return true;
  if(ccw(a0,a1,b0)<=0&&ccw(a0,a1,b1)>=0&&ccw(b0,b1,a0)>=0&&ccw(b0,b1,a1)<=0) return true;
  return false;
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
 	vector<seg> vrt;
    vector<seg> hrt;     
    int n; 
    cin >> n; 
    double x1, y1, x2, y2; 
    forn(i,n){
        cin >> x1 >> y1 >> x2 >> y2;
        if(isVertical(x1, y1, x2, y2)){
            vrt.pb(seg(point(x1,y1) , point(x2,y2)));
        }else{
            hrt.pb(seg(point(x1,y1) , point(x2,y2)));       
        }
    }
    int ntc = 0;
    int lv  = len(vrt) , lh = len(hrt);
    int ok =1;
    for(int h = 0 ; h < lh && ok; h++){
        seg a = hrt[h];
        for(int h2 = h+1 ; h2 < lh; h2++){
            seg b = hrt[h2];
            for(int v = 0 ; v<lv ; v++){
                seg a1 = vrt[v];
                for(int v2 = v+1 ; v2<lv;v2++){
                    seg b1 = vrt[v2];
                    if(intss(a.x,a.y,a1.x,a1.y) &&  intss(a.x,a.y,b1.x,b1.y)    &&    intss(b.x,b.y,a1.x,a1.y) &&  intss(b.x,b.y,b1.x,b1.y) ) {
                        ntc++;
                    }
                }
            }
        }
    }
	cout <<  ntc << endl;
    
    

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


