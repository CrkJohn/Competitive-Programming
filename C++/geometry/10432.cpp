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




int main(){
	//lec();
	//https://www.mathopenref.com/polygonregulararea.html
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  double r;int n;
  cout << fixed;
  cout.precision(3);
  while(cin >> r >> n){
			cout << (r * r * n * sin(DEG_TO_RAD(360.0/n))) / 2.0 << endl;
	}
	return 0;
}

