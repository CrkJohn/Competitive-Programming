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


using namespace std;


struct point{
	double x,y;
	point(){x = y = 0.0;}
	point(int X,int Y){
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

double dist(point a, point b){
	return hypot(a.x-b.x,a.y-b.y);
}

double cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r){
		return cross(q-p,r-p)>0;
}


point pivot;

bool angleCmp(point a,point b){
	if(fabs(cross(a-pivot,b-pivot))< eps){
			return dist(a,pivot)< dist(b,pivot);
	}
  point x = a-pivot, y = b-pivot;
  return atan2(x.y,x.x) - atan2(y.x,y.y) < 0;
}

vector<point> CH(vector<point> P){
	int n = si(P);
	if(n<=3){
			if(!(P[0]==P[n-1]))P.pb(P[0]);
			return P;
	}
	int P0 = 0;
	for1(i,n-1){
		if(P[i].y < P[P0].y || (P[i].y== P[P0].y && P[i].x > P[P0].x  )){
				P0 = i;
		}
	}
	swap(P[0],P[P0]);
	pivot = P[0];
	sort(++P.begin(),P.end(),angleCmp);
	vector<point> S;
	S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
	int i = 2,j;
	while(i<n){
			j = si(S)-1;
			(ccw(S[j-1], S[j], P[i]))?S.pb(P[i++]):S.pop_back();
	}
	return S;
}

double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  forn(i,(int)P.size()-1){
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0;
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
      if(cases==100)cout << n << endl;
			forn(i,n){
					cin >> pts[i].x >> pts[i].y;
					if(cases==100)cout << pts[i].x <<" "<<  pts[i].y << endl;
			}
			vector<point> ch = CH(pts);


			int B = si(ch);
			double  A = area(ch);
			//cout <<"Case "<<cases<<": "<<   floor(A+1 - (B/2))<< endl;
	}
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

	return 0;
}
