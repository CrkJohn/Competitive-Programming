#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define forn(i,a,b) for(int i = a; i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define eps 1e-9
#define INF 1e9
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

struct dragon{
	 int f,bonus;
	 bool operator <(const dragon other)const{
				return f<other.f;
	 }
};

int main(){
	//lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
  int s,n;
  cin>> s >> n;
  dragon d[n+1];
	forn(i,0,n-1){
			cin >>  d[i].f >> d[i].bonus;
	}
	sort(d,d+n);
	int f = 1;
	FOR(i,n){
      if(d[i].f < s){
						s += d[i].bonus;
      }else{
					 f = 0;
					break;
      }
	}
	cout << ((f == 1 ) ? "YES" : "NO") << endl;
	return 0;
}
