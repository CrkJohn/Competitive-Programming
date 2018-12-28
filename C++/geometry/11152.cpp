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

double DEG_to_RAD(double d){
	 return d * PI / 180.0;
}

double areaHeron(double a, double b, double c){
		double s = (a+b+c)*0.5;
		double A = (s*(s-a)*(s-b)*(s-c));
		return sqrt(A);
}


double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * areaHeron(ab, bc, ca));
}

double rInCircle(double ab, double bc, double ca) {
  return areaHeron(ab, bc, ca) / (0.5 * (ab+bc+ca));
}


int main(){
	in();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cout.precision(4);
	cout << fixed;
	int ntc = 1;
	while(1){
      double a,b,c;
      cin >> a >> b >> c;
      if(cin.eof())break;
      double areaTriangulo = areaHeron(a,b,c);
			double circumCicle  = rCircumCircle(a,b,c);
			double incirCicle  =  rInCircle(a,b,c);
      cout <<(circumCicle*circumCicle*PI)-areaTriangulo<<" "<< areaTriangulo-(incirCicle*incirCicle * PI) <<" " <<  (incirCicle*incirCicle * PI)<< endl;

	}
	return 0;
}
