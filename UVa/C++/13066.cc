#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define INF 1e9
#define eps 1e-9
#define PI acos(-1.0)
#define si(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define for1(i,n) for(int i=1;i<=(int)(n); ++i)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)

#define out2() freopen("out2.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long large;



double DEG_to_RAD(double d){return d*PI/180.0;}
double RAD_to_DEG(double r){return r*180.0/PI;}

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

ostream & operator<< (ostream &out, const point &c){
	out << "x =" << c.x << ",y = " << c.y << ";";
    return out;
}

double cross(point a, point b){
//	cerr << "\t a : " << a << "b : " << b << endl;
	return a.x*b.y - a.y *b.x;
}

point pivot;

double dist(point p, point q){
	return hypot(p.x-q.x,p.y-q.y);
}

//Alternatica ccw-usando struct point
bool ccw(point p,point q, point r){
    return cross(q-p,r-p)>0;
}

bool angleCmp(point a, point b) {
  if (fabs(cross(a-pivot,b-pivot)) < eps)
        return dist(pivot, a)<dist(pivot, b);
  point  d1  = a-pivot,d2= b-pivot;
  return(atan2(d1.y, d1.x)-atan2(d2.y,d2.x))<0;
}

vector<point> CH(vector<point> P) {
  int i, j, n = (int)P.size();
  if (n <= 3){
    if (!(P[0] == P[n-1])) P.pb(P[0]);
    return P;
	}
	int P0 = 0;
  for1(i,n)
    if (P[i].y<P[P0].y || (P[i].y==P[P0].y && P[i].x>P[P0].x))P0 = i;
  swap(P[0],P[P0]);
  pivot = P[0];
  sort(++P.begin(), P.end(),angleCmp);
  vector<point> S;
  S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
  i = 2,j;
  while(i<n){
    j = (int)S.size()-1;
		(ccw(S[j-1], S[j], P[i]))?S.pb(P[i++]):S.pop_back();
  }
  return S;
}


double heron(point a, point b, point c){
    double ab = dist(a,b);
    double bc = dist(b,c);
    double ca = dist(c,a);
    double s = (ab+bc+ca)/2.;
    return sqrt(s * (s-ab)* (s-bc) * (s-ca));
}


int main(){
    in();//freopen quitar antes de un envio
    //out();//freopen quitar antes de un envio
    out2();
    ios::sync_with_stdio(0);
  	cin.tie(0);
  	cout << fixed;
  	cout.precision(1);

    int n;
    while(cin >> n){
        vector<point> pts(n);
        forn(i,n){
            cin >> pts[i].x >> pts[i].y;
        }
        vector<point> ch = CH(pts);

        int lenCh = si(ch);
        int i = 0  , j = 1 ,  k = 2;
        double area = .0;
        while(i < lenCh){
            j = i+1;
            while(j < lenCh){
                k = j  + 1;
                while(k < lenCh){
                    double A = heron(pts[i],pts[j],pts[k]);
                    if(area < A){
                        area  = A;
                    }else{break;}
                    k++;
                }
                j++;
            }
            i++;
        }
        cout << area << endl;
    }
    cerr << "Time elapsed: ";
    cerr << 1.0 * clock() / CLOCKS_PER_SEC;
    cerr << " s.\n";
    return 0;
}


