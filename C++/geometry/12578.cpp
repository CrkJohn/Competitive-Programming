#include<bits/stdc++.h>
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

const double PI = acos(-1.0);
#define DEG_TO_RAD(a)  (a*(PI/180.0))

/*
	Author : John David Ibanez
	Time: 0s
	Accepted
*/

int main(){
	//lec();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
  cout.precision(2);
  cout<< fixed;
  cin >> ntc;
  double l;
  while(ntc--){
			cin >> l;
      double six = l*6.0/10.0;
      double two = six*2.0/6.0;
			double areaCircle = two*two * PI;
			double areaRect = l*six - areaCircle;
      cout << areaCircle <<" " << areaRect  << endl;
  }
	return 0;
}
