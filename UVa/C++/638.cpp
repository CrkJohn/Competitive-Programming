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


const int maxn = 51;

void solve(){
	int ntc = 1;
	while(1){
		   int n;char c;
      cin >> n;
      if(n==0)break;
			vector<point> pts(n);
			char id[maxn][maxn];
			forn(i,maxn)forn(j,maxn)id[i][j] = '$';
			forn(i,n){
					cin >> c >> pts[i].x >> pts[i].y;
					id[pts[i].x][pts[i].y] = c;
			}
			set<string> sq;
			string str;
      forn(i,n){
					fore(j,i+1,n){
							point a  = pts[i], b  = pts[j];

							ll bottomRightX  = min(a.x,b.x), bottomRightY = min(a.y,b.y);
							ll bottomLeftX  = max(a.x,b.x), bottomLeftY = min(a.y,b.y);
							ll topRX  = max(a.x,b.x), topRY = max(a.y,b.y);
							ll topX  = min(a.x,b.x), topY = max(a.y,b.y);
							if(id[bottomRightX][bottomRightY]!='$' && id[bottomLeftX][bottomLeftY]!='$' &&
								 id[topRX][topRY]!='$' && id[topX][topY]!='$'
								 && topRY!=bottomLeftY && topX != bottomLeftX

								 ){
//								 	 cerr << a.x << " " << a.y << " " << b.x << " " << b.y <<endl;
//								 	 cerr <<  bottomRightX  << " " <<  bottomRightY << endl;
//								 	 cerr <<  bottomLeftX  << " " <<  bottomLeftY << endl;
//								 	 cerr <<  topRX  << " " <<  topRY << endl;
//								 	 cerr <<  topX  << " " <<  topY << endl;
									 str = "";
								 	 str.pb(id[topX][topY]);
									 str.pb(id[topRX][topRY]);
								 	 str.pb(id[bottomLeftX][bottomLeftY]);
								 	 str.pb(id[bottomRightX][bottomRightY]);
								 	 sq.insert(str);
							}
					}
      }
			cout << "Point set "<<ntc++<<":";
      if(si(sq)==0){
					cout << " No rectangles\n";
      }else{
					cout << "\n";
					int sz = 0;
					for(auto sti : sq){
							cout << " " << sti;
							sz++;
							if(sz == 10){
								sz = 0;
								cout << endl;
							}
					}if(sz!=0)cout << endl;
			}

	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout << fixed;
	cout.precision(10);
	int ntc = 1;
	//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
	solve();


	return 0;
}
