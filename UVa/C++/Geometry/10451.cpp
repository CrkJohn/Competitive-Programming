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


int main(){
	//lec();
	//https://www.mathopenref.com/polygonregulararea.html
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout << fixed;
  cout.precision(5);
	int n,ntc = 1; double A;
  while(1){
				cin >> n >> A;
				if(n<3)break;
        long double  r  = sqrt((2*A)/(n*sin(DEG_TO_RAD(360.0/n))));
        long double  lawCosines = sqrt(r*r+r*r - 2*r*r * cos(DEG_TO_RAD(360.0/n))) / 2.;
        double pyt = sqrt(r*r - lawCosines*lawCosines);
        cout << "Case " << ntc++ << ": ";
				cout << (r*r*PI)-A << " " << A-pyt*pyt*PI << endl;

	}
	return 0;
}


