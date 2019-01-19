#include<bits/stdc++.h>
#define forn(i,n) for(int i = 0; i<n;i++)
#define for1(i,n) for(int i = 1; i<=n;i++)
#define fore(i,a,n) for(int i = a; i<=n;i++)
#define ford(i,n) for(int i = n; i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define si(a) ((int)a.size())
#define eps 1e-9
#define NEXT(i,n) (((i) + 1) % n)

/*
	Veredict = time limit
*/

using namespace std;
typedef long long ll;

struct point{
	ll x,y;
	point(){x = y = 0.0;}
	point(ll X,ll Y){
			x = X;
			y = Y;
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





double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  forn(i,(int)P.size()-1){
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0;
}

ll points_on_segment(const point p,const point q){
	point pq = p - q;
	return __gcd(abs(pq.x), abs(pq.y));
}


double pickTheorem(vector<point> &P){
	double A = area(P);ll B = 0;double I = 0;
	int n = si(P);
	forn(i,n)
		B += points_on_segment(P[i], P[NEXT(i,n)]);
	A = fabs(A);
	I = A-(B/2.) + 1;
	return I;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int ntc;
	cin >> ntc;
	for1(cases,ntc){
			int n;
			cin >> n;
			vector<point> pts(n);
			forn(i,n){
					cin >> pts[i].x >> pts[i].y;
			}
			cout <<"Case "<<cases<<": "<<   pickTheorem(pts)<< endl;
	}
	return 0;
}
