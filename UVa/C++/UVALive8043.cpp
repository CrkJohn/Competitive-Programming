#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define forn(i,n) for(int i = 0 ; i<n;i++)
#define for1(i,n) for(int i = 1 ; i<=n;i++)
#define fore(i,a,b) for(int i = a ; i<b;i++)
#define ford(i,n) for(int i = n ; i>=0;i--)
#define mp make_pair
#define eps 1e-9
#define INF 1e9
#define si(a) ((int)a.size())

using namespace std;


typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<pii> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


struct point{
	ll x,y;
	point(){x  =  y = .0;}
	point (ll X,ll Y){
			x =X;
			y =Y;
	}
};


const int maxn = 1010;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
  cout << fixed;
	cout.precision(9);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
  int n;double t;
  while(cin >> n >> t){
				double mx = 1e9, mn = 1e9;
				vector<pdd> ds(n);
				forn(i,n){
					cin >> ds[i].fi >> ds[i].se;
					mn = min(ds[i].se,mn);
				}
				mn = -1.0 * mn + eps;
				while(mx-mn>=eps){
						double mid = (mx+mn)*.5;
						double tPrevio = .0;
						forn(i,n){
								tPrevio += (ds[i].fi/(ds[i].se+mid));
            }
            if(tPrevio>t){
								mn = mid;
            }else{
								mx = mid;
						}
				}
				cout << mn << endl;
  }
	return 0;
}
