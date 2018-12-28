#include<bits/stdc++.h>
#define in() freopen("in.txt","r",stdin);freopen("out.txt","w",stdout)
#define FOR(i,n) for(int i = 0; i<n; i++)

using namespace std;

double const PI = acos(-1.0) , EPS  = 1e-9;;

struct point{
	double x,y;
	point(){x = y = 0.0;}
	point(int X,int Y): x(X) , y(Y){};
	/*point& operator =(point other)const{
			*this.x = other.x;
			*this.y = other.y;
			return *this;
	}*/
	bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); };
};


ostream & operator << (ostream &out, const point &c){
		out << "(" << c.x << "," << c.y << ") ";
    return out;
}

double dist(point a, point b){
	return sqrt(pow(a.x-b.x,2.) + pow(a.y-b.y,2.0));
}

int circumCircle(point p1, point p2, point p3, point &ctr, double &r){
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPS) return 0;
  ctr.x = (d*e - b*f) / g;
  ctr.y = (a*f - c*e) / g;
  r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
  return 1;
}

double DEG_to_RAD(double d){
	 return d * PI / 180.0;
}


point rotate(point pivot,double angle,point p){
	double rad = DEG_to_RAD(angle);    // multiply theta with PI / 180.0
  double s = sin(rad);
  double c = cos(rad);
  // translate point back to origin:
  p.x -= pivot.x;
  p.y -= pivot.y;
  // rotate point
  double xnew = p.x * c - p.y * s ,  ynew = p.x * s + p.y * c;
  // translate point back:
  p.x = xnew + pivot.x;
  p.y = ynew + pivot.y;
  return p;
}


int main(){
	//in();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cout.precision(3);
	cout << fixed;
	int ntc = 1;
	while(1){
		cin >> n;
		if(n==0)break;
		point p,q,k,ctr;
		double r;
		cin >> p.x >> p.y >> q.x >> q.y >> k.x >> k.y;
		int can = circumCircle(p,q,k,ctr,r);
		double tetha  = 360.0/n;
		double INF = (double)1e9;
		double minx = INF,miny = INF,maxy = -INF,maxx = -INF;
    FOR(i,n){
        point tmp = rotate(ctr,tetha,p);
        miny = min(tmp.y,miny);
				maxy = max(tmp.y,maxy);
				minx = min(tmp.x,minx);
				maxx = max(tmp.x,maxx);
        p.x  = tmp.x; p.y = tmp.y;
	  }
	  cout << "Polygon "<<ntc++<< ": ";
		cout <<(maxy-miny)*(maxx-minx)<< endl;

	}
	return 0;
}
