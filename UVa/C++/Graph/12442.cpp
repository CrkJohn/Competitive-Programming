#include<bits/stdc++.h>
#define FOR(i,b) for(int i=0;i<b;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define pb push_back
#define INF 1e9
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

const int maxn = 50001;
const int dx[] = {0,-1,0,1} , dy[] = {1,0,-1,0};

vvi g;
int padre[maxn];
int vis[maxn];
int paths[maxn];


int dfs(const int &p){
    if(vis[p])return 0;
    vis[p] = 1;
    int lonPath = dfs(padre[p]);
    vis[p] = 0;
    return paths[p] = lonPath  + 1;
}



int main(){
	lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
	cin>> ntc;
	int res;
	forn(ctn,1,ntc){
			int N; cin >> N;
			FOR(i,N){
				 int u,v;
				 cin >> u >> v;
				 padre[u] = v;
			}
			forn(i,1,N)paths[i]=-1;
			memset(vis,0,sizeof vis);
			forn(nodes,1,N)if(paths[nodes]==-1){
				dfs(nodes);
			}
			int maxPath = -INF,u;
			forn(nodes,1,N){
				if(paths[nodes]>maxPath){
							maxPath = paths[nodes];
							res = nodes;
				}
			}
			cout << "Case "<<ctn<<": "<< res<<endl;
	}
	return 0;
}
