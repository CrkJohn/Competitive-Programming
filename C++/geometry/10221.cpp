#include<bits/stdc++.h>
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
using namespace std;
const long double PI = acos(-1.0);
#define DEG_TO_RAD(a)  (a*(PI/180.0))

/*
	Author : John David Ibanez
	Time:

*/

int main(){
	//lec();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(6);
	cout << fixed;
	long double s,a;
	string str;
	while(cin >> s >> a >> str){
			// 1 hr - 30°
			// 1 min  60°
			//  ARC = 2*PI*R/ 360.0 * angulo
			if(str=="min"){
         a /=60;
      }
      while(a>180.0)a=360.0-a;
      s += 6440;
      cout << DEG_TO_RAD(a) * s << " ";
			cout << sqrt((s*s+s*s) - 2.0*s*s*cos(DEG_TO_RAD(a)))<< endl;
	}
	return 0;
	/*
	500 30 deg
	700 60 min
	200 45 deg
	*/
}
