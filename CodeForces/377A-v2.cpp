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
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef double ld;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

const int maxn = 600;

char graph[maxn][maxn];
int vis[maxn][maxn];
int n,m,k;

void dfs(int xx , int yy){
   if(vis[xx][yy])return;
   vis[xx][yy] = 1;
   forn(i,4){
			int x = xx + dx[i] , y = yy + dy[i];
			if(0 <= x  && x<n && 0<=y && y <m  && !vis[x][y]  && graph[x][y] == '.'){
					 dfs(x,y);
			}
   }
   if(k){
			graph[xx][yy] = 'X';
			k--;
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    //in();
		cin >> n >>  m >> k;
		forn(i,n){
				cin >> graph[i];
		}
		memset(vis,0,sizeof vis);
		forn(i,n){
			forn(j,m){
					if(graph[i][j] == '.') dfs(i,j);
			}
		}
		forn(i,n){
			forn(j,m){
				cout << graph[i][j];
			}
			cout << endl;
		}

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
