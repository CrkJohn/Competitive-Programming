#include<bits/stdc++.h>
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define FOR(i,b) for(int i = 0 ; i< b; i++)
#define loop(i,a,b) for(int i = a ; i< b; i++)
#define fors(i,a,b,s) for(int i=a;i<b;i=i+s)
#define pb push_back
using namespace std;


const double PI = acos(-1.0);
#define DEG_TO_RAD(a)  (a*(PI/180.0))

/*
	Author : John David Ibanez
	Time:


*/

const double EPS = 1e-9;
struct point{
	double x,y;
	point(){ x= y = 0.0;}
  point(double X, double Y): x(X) , y(Y){}
	bool operator <(point other) const{
			if(fabs(x-other.x)<EPS){
					return x < other.x;
			}
			return y < other.y;
  }
};

ostream & operator << (ostream &out, const point &c){
		out << "(" << c.x << "," << c.y << ")\n";
    return out;
}

vector<point> pts;


short int circle2PtsRad(const point p1,const point p2, double r){
  double d2 = (p1.x-p2.x)*(p1.x-p2.x)
							+ (p1.y-p2.y)*(p1.y-p2.y);
  double det = r * r / d2 - 0.25;
  if(det<0.0) return 0;
  return 1;
}



int main(){
	lec();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  while (1){
			int numPoints ; cin >> numPoints;
			if (numPoints==0)break;
			pts.clear();
			FOR(i,numPoints){
					double x ,y;
					cin >> x >> y;
					pts.pb(point(x,y));
			}
			sort(pts.begin(),pts.end());
			double r;cin >> r;
			short int f = 1;
			//pts.pb(pts[0]);
		  loop(i,0,numPoints-1){
          point a,b;
          a = pts[i];
          b = pts[i+1];
					cerr << a << " " << b;
					f = circle2PtsRad(a,b,r);
					if(f==0)break;
			}
			if(f ){
				cout << "The polygon can be packed in the circle." <<endl;
			}else{
				cout << "There is no way of packing that polygon." << endl;
			}
  }
	return 0;
}

