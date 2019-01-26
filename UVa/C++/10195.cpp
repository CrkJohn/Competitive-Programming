#include<bits/stdc++.h>
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define FOR(i,b) for(int i = 0 ; i< b; i++)
#define loop(i,a,b) for(int i = a ; i< b; i++)
#define fors(i,a,b,s) for(int i=a;i<b;i=i+s)
#define pb push_back
#define fi first
#define se second

using namespace std;

/*
	Author : John David Ibanez
	Time:

*/

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<double,int> di;
typedef vector<di> vid;
typedef vector<vid> vvid;

vvid g;


const double EPS = 1e-9;
const int MAX_N = 1100;

int dis[MAX_N];


typedef pair<double,double> dd;


ostream & operator << (ostream &out, const dd &c){
		out << "(" << c.fi << "," << c.se << ")\n";
    return out;
}



int main(){
	//lec();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout << fixed;
  cout.precision(3);
	double v,m;
	while(1){
			double a,b,c;
			cin >> a >> b >> c;
			if(cin.eof())break;
			double p =  a+b+c;
			double s = p * 0.5;
			double A = sqrt(s*(s-a)*(s-b)*(s-c));
			if(s==0.0) s=1;
			double r = A/s;

			cout  << "The radius of the round table is: "<<r<<"\n";
	}
	return 0;
}




