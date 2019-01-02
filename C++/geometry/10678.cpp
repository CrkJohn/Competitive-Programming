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
		out << "x =" << c.fi << ", y = " << c.se << ";";
    return out;
}

const double pi = (double)acos(-1);

int main(){
	//lec();
	//www.universoformulas.com/matematicas/geometria/elementos-elipse/
	ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(3);
  int ntc;
  cin >> ntc;
  FOR(i,ntc){
		double d,l;cin >> d >> l;
		double a = l/2.;
		double b = sqrt(a*a - (d/2. * d/2.0));
		cout << pi * a * b << endl;
  }
	return 0;
}
