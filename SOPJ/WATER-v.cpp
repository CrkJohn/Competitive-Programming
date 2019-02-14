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
#define si(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pi64;
typedef double ld;

int n , m;
const int maxn = 110;
int g[maxn][maxn];
int vis[maxn][maxn];


int dxc[] = {-1 , -1 -1 , 0, 0,1 , 1 ,1};
int dyc[] = {-1 , 0 , 1  , -1, 1,-1 , 0 ,1};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs(pii src){
	queue<pii> q;
  q.push(src);
  vis[src.fi][src.se] = 1;
	while(!q.empty()){
			pii u = q.front(); q.pop();
      forn(i,4){
					int h = u.fi  + dx[i]  , k = u.se + dy[i];
          if(g[u.fi][u.se]<=g[h][k] && (0<= h && h<n && 0<=k && k <m) && !vis[h][k]){
							vis[h][k] = 1;
							q.push({h,k});
					}
      }
	}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int ntc;
    //in();
    cin >> ntc;
		forn(t,ntc){
				cin >> n >> m;
				forn(i,n){
					forn(j,m){
							cin >> g[i][j];
					}
				}
				memset(vis,0,sizeof vis);
				forn(i,n)if(!vis[0][i])bfs({0,i});
				forn(i,n)if(!vis[i][0])bfs({i,0});
				forn(i,n)if(!vis[n-1][i])bfs({n-1,i});
				forn(i,n)if(!vis[i][m-1])bfs({i,m-1});

				ll ans = 0;
				forn(i,n){
						forn(j,m){

									if(vis[i][j] == 0){
											int mini = 1e9;
											forn(t,4){
												int h = i + dx[t] , k = j + dy[t];
												if((0<= h && h<n && 0<=k && k <m) && g[h][k]>g[i][j] ){
														mini = min(g[h][k]-g[i][j],mini);
										//				cout << (g[h][k]-g[i][j]) << " " << h <<" " <<  k <<   endl;
 												}
											}
									g[i][j]+=mini;
									//cout << endl;
									ans+=mini;
							}
					}
				}
				cout << ans << endl;
		}

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

