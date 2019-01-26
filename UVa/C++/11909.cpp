#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define rev(i,a,b) for(int i = a; i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long large;

ostream & operator << (ostream &out, const ii &c){
		out << "(" << c.fi << "," << c.se << ") ";
    return out;
}

const double PI = acos(-1);

double DEG_TO_RAD(const double angle){
	return angle* PI/180.0;
}

int main(){
	//lec();
	ios::sync_with_stdio(0);
  cin.tie(0);
	int l,h,w;
	double angle;
	cout << fixed;
	cout.precision(3);
	double volBox;
	while(1){
		cin >> l >> w >> h;
		if(cin.eof())break;
		cin >> angle;
		double cat = tan(DEG_TO_RAD(angle)) * l;
		if(cat<=h){
			 double  volT =  ((l*cat*w)*.5);
			 volBox = (h*w*l) - volT;
		}else{
			double complementAngle = 90.0 - angle;
			double b = h * tan(DEG_TO_RAD(complementAngle));
      volBox = w*(h*b)* .5;
		}
    cout << volBox << " mL\n";
	}
	return 0;
}
