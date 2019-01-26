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
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define eps 1e-9
#define si(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


ostream & operator << (ostream &out, const pii &c){
	out << "x =" << c.fi << ", y = " << c.se << ";";
    	return out;
}

const double pi = (double)acos(-1.0);

struct point{
	double x,y;
	point(){x= y = 0.0;}
	point(double X ,double Y){
			x =  X;
			y = Y;
	}
  bool operator <(const point &other){
      if(fabs(x-other.x) > eps){return x < other.x;}
      return y < other.y;
  }
	bool operator==(const point &a) const {
			return fabs(x-a.x) < eps && fabs(y-a.y) < eps;
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

typedef vector<point> poly;

point pivot;

double dist(point a, point b){
	return hypot(a.x-b.x,a.y-b.y);
}

double cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q , point r){
		return cross(q-p,r-p) > 0;
}

bool angleCmp(point a, point b){
		if(fabs(cross(a-pivot,b-pivot))<eps)
				return dist(a,pivot) < dist(b,pivot);
		point d1 = a-pivot, d2 = b-pivot;
		return atan2(d1.y,d1.x) - atan2(d2.y,d2.x) <0;
}




poly convexHull(poly P){
		int n = si(P);
		if(n>0 && n<=3){
			if(!(P[0]==P[n-1]))P.pb(P[n-1]);
			return P;
		}
		int tmp = 0;
		for1(i,n-1)if(P[i].y < P[tmp].y || (P[i].y == P[tmp].y && P[i].x>P[tmp].x)){
					tmp = i;
		}
		swap(P[tmp],P[0]);
		sort(++P.begin(),P.end(),angleCmp);
		pivot = P[0];
		poly S;
		S.pb(P[n-1]);S.pb(P[0]);S.pb(P[1]);
		int i = 2, j;
		while(i<n){
			j = (int)S.size()-1;
			(ccw(S[j-1], S[j], P[i]))?S.pb(P[i++]):S.pop_back();
		}
		cerr << "S size " << si(S) << endl;

		return S;
}

double perimeter(poly p){
		double res  = 0.0;

		int n = si(p);
		forn(i,n-1){
			res+= dist(p[i],p[i+1]);
		}
		return res;
}

int main(){
		ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    in();

		int n,l;
		cin >> n >> l;
		poly p(n);
		forn(i,n){
				cin >> p[i].x >> p[i].y;
		}
		poly s = convexHull(p);
		cerr << si(s) << endl;

		double per =perimeter(s) , PI = acos(-1.);
		per+=(2*l*PI);
		cerr << "perimeter end" << endl;

		cout << per  << endl;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}
