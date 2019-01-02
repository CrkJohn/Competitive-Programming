#include<bits/stdc++.h>
#define FOR(i,b) for(int i =0  ; i<b;i++)
#define fi first
#define se second
#define pb push_back
#define INF 1e9
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

const int maxn = 50;
const int dx[] = {0,-1,0,1} , dy[] = {1,0,-1,0};

vvi g;


int main(){
	lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
	cin>> ntc;
	int res;
	FOR(ctn,ntc){
			int N; cin >> N;
			g.assign(vi(),N+1);
			FOR(i,N){
				 int u,v;
				 cin >> u >> v;
				 g[u].pb[v];
//			 g[v].pb[u];
			}

			cout << "Case "<<ctn<<": "<< res<<endl;
	}

	return 0;
}
