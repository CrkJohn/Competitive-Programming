#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define rev(i,a,b) for(int i = a; i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define INF 1e9
#define eps 1e-9
#define PI acos(-1.0)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long large;

ostream & operator << (ostream &out, const ii &c){
		out << "u :  " << c.fi << " ->  v : " << c.se << ";";
    return out;
}


double DEG_to_RAD(double d) { return d * PI / 180.0;}
double RAD_to_DEG(double r) { return r * 180.0 / PI;}

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

ostream & operator << (ostream &out, const point &c){
		out << "x =" << c.x << ", y = " << c.y << ";";
    return out;
}

double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double


struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }



point translate(point p, vec v) {        // translate p according to v
  return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y);}

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }


vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
  return vec(v.x * s, v.y * s); }               // shorter.same.longer


double distToLine(point p, point a, point b, point &c) {
  // formula: c = a + u * ab
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));                  // translate a to c
return dist(p, c); }           // Euclidean distance between p and c



double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) { c = point(a.x, a.y);                   // closer to a
    return dist(p, a); }         // Euclidean distance between p and a
  if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
    return dist(p, b); }         // Euclidean distance between p and b
  return distToLine(p, a, b, c); }          // run distToLine as above



int main(){
	//lec();
	ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(4);
  point m;
  while(1){
			cin >> m.x >> m.y;
			if(cin.eof())break;
			int N;cin >> N;
			vector<point> pts;
//			cerr << 2*N+2 << " N : " << N << endl;
  			FOR(i,N+1){
				 double x,y;
				 cin >> x >> y;
				 pts.pb(point(x,y));
//				 cerr << pts[pts.size()-1]  << endl;
			}

			double ansDis = INF;
			point ansPoints,tmp;
			FOR(i,pts.size()-1){
					double dis = distToLineSegment(m,pts[i],pts[i+1],tmp);
					if(dis<ansDis){
								ansDis = dis;
								ansPoints = tmp;
					}
//					cerr << "Ans Point " << ansPoints <<"dis min " << dis<<    endl;
			}
			cout << ansPoints.x << "\n" << ansPoints.y << endl;
  }
	return 0;
}
