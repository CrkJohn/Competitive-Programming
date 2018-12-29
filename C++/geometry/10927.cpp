#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define rev(i,a,b) for(int i = a; i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define si(a) ((int)a.size())

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long large;


const double EPS = (double)1e-11 , PI = acos(-1);

double RAD_TO_DEG(double rad){
	return rad * 180.0 /  PI;
}


struct  point{
	 double x,y;
	 double z;
	 point(){x = y = z = .0;}
	 point(double X, double Y,double Z): x(X), y(Y) , z(Z){};
};


ostream & operator << (ostream &out, const point &c){
		out << "x = " << c.x << ", y = " << c.y << "";
    return out;
}



double angle(point a){
	return atan2(a.y,a.x);
}

double dist(point a, point b ){
		return sqrt(pow(a.x-b.x,2.0) + pow(b.y-a.y,2.));
}


bool cmp(point a, point b){
	point ORIGIN;
	double angleThis = angle(a);
	double angleOther = angle(b);
	if (fabs(angleThis - angleOther) > EPS) {
			return angleThis < angleOther;
	}
	return dist(a, ORIGIN) < dist(b, ORIGIN);
}

bool cmp2(point p1, point p2){
	if (fabs(p1.x - p2.x) > EPS)
			return p1.x < p2.x;
		return p1.y < p2.y;
}


int main(){
  //lec();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ntc = 1;
  while(1){
			int n; cin >> n;
			if(n==0)break;
			vector<point> pts;
			FOR(i,n){
				point p;
				cin >> p.x  >> p.y >> p.z;
				pts.pb(p);
			}
			sort(pts.begin(),pts.end(),cmp);
			point iniPoint = pts[0];
			double iniAng = angle(iniPoint);
			vector<point> res;
			loop(i,1,n){
					point tmp = pts[i];
					double ang =  angle(tmp);
          				if(fabs(ang-iniAng)<EPS)// mismo angulo
					{
							if(iniPoint.z >= tmp.z){
                  						res.pb(tmp);
							}else{
									iniPoint = tmp;
							}
          				}else{
							iniPoint = tmp;
							iniAng = angle(iniPoint);
					}
			}
			int lon = si(res);
			sort(res.begin(),res.end(),cmp2);
			cout << "Data set "<<ntc++<<":\n";
			if(lon == 0){
					cout << "All the lights are visible.\n";
			}else{
        			cout << "Some lights are not visible:\n";
				FOR(i,lon-1){
						cout << "x = "<<(int)res[i].x<<", y = "<<(int)res[i].y<<";\n";
				}
				cout << "x = "<<(int)res[lon-1].x<<", y = "<<(int)res[lon-1].y<<".\n";
			}
	}
	return 0;
}
