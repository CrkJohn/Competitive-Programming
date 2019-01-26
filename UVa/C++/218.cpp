#include<bits/stdc++.h>

#define fore(i,a,b) for(int i = a; i<b;i++)
#define forn(i,b) for(int i = 0; i<b;i++)
#define for1(i,b) for(int i = 1; i<=b;i++)
#define ford(i,a,b) for(int i = a; i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define si(a) ((int)a.size())
#define eps 1e-10
#define all(x) (x).begin(),(x).end()


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



double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result; }


point pivot;

double cross(point a, point b){
//	cerr << "\t a : " << a << "b : " << b << endl;
	return a.x*b.y - a.y *b.x;
}


bool ccw(point p,point q, point r){return cross(q-p,r-p)>0;}

bool collinear(point p, point q, point r) {
//	cerr << "p : " << p << " q : " << q << " r : " << r << endl;
  return fabs(cross(q-p,r-p)) < eps; }



bool angleCmp(point a, point b) {                 // angle-sorting function
  if (fabs(cross(a-pivot,b-pivot)) < eps)
		return dist(pivot, a)<dist(pivot, b);    // check which one is closer
  point  d1  = a-pivot, d2 = b - pivot;
  return (atan2(d1.y, d1.x) - atan2(d2.y, d2.x)) < 0;
}

vector<point> CH(vector<point> P) {
  int n = (int)P.size();
  if (n <= 3){
    if (!(P[0] == P[n-1])) P.pb(P[0]);
    return P;
	}
	int P0 = 0;
  for1(i,n-1)if (P[i].y<P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))P0 = i;
	swap(P[0],P[P0]);
  pivot = P[0];
  sort(++P.begin(), P.end(),angleCmp);
  vector<point> S;
  S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
  int i = 2,j;
  while(i<n){
    j = (int)S.size()-1;
		(ccw(S[j-1], S[j], P[i]))?S.pb(P[i++]):S.pop_back();
  }
  return S;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed;
  int n;
  //lec();
  int f  = 0;
  int ntc = 1;
  while(cin >> n,n){
			vector<point> pts;
			forn(i,n){
				double x , y;
				cin >> x >> y;
				pts.pb(point(x,y));
			}
			vector<point> ch =  CH(pts);
      if(f) cout << endl;
      f = 1;
      cout.precision(1);
      cout << "Region #"<<ntc++<<":\n";
      reverse(all(ch));
      forn(i,si(ch)-1){
					cout << "("<<ch[i].x << "," << ch[i].y << ")-";
      }
			cout << "("<<ch[si(ch)-1].x << "," << ch[si(ch)-1].y << ")\n";
      cout.precision(2);
      cout << "Perimeter length = "<< perimeter(ch)<<endl;
  }
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}

