#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)


using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

int n,m;

const int maxn = 111;

bool let(const int x, const int y){
	return  0<=x && x<n && 0<=y && y<m;
}

const int dx[] = {-1,1,0,   1,-1, -1,0,1} ;
const int dy[]=  {-1,-1,-1, 0,0,  1,1,1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
		int f = 0;
		//in();
		//out();
		int ntc  = 1;
		while(1){
			cin >> n >> m;
			if(n+m==0)break;
			string str;
			getline(cin,str);
			vector<string> mine(n);
			forn(i,n){
					cin >> mine[i];
			}
			if(f) cout << endl;
			f = 1;
			int result[maxn][maxn];
			forn(i,n)forn(j,m)result[i][j] = 0;
			forn(i,n){
				forn(j,m){
						forn(t,8){
							int k = dx[t] + i , h = dy[t] + j;
							if(let(k,h) && mine[i][j] == '*' && mine[k][h]!='*'){
										result[k][h]+=1;
							}
						}
				}
			}
			cout << "Field #"<<ntc++<<":"<<endl;
			forn(i,n){
				forn(j,m){
					if(mine[i][j]=='*'){
							cout << '*';
					}else{
						cout << result[i][j];
					}
				}
				cout << endl;
			}
		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
