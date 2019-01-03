#include<bits/stdc++.h>
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define FOR(i,b) for(int i = 0 ; i< b; i++)
#define loop(i,a,b) for(int i = a ; i< b; i++)
#define fors(i,a,b,s) for(int i=a;i<b;i=i+s)
#define pb push_back


using namespace std;

/*
	Author : John David Ibanez
	Time:

*/

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;


const double EPS = 1e-9;
const int MAX_N = 1100;

int dis[MAX_N];


void bfs(int src,const int &n){
	queue<int> q;
	q.push(src);
	FOR(i,n)dis[i] = -1;
	dis[src] = 0;
  while(!q.empty()){
			int u = q.front(); q.pop();
			for(const int &v: g[u]){
					if(dis[v]==-1){
							dis[v] = dis[u] + 1;
							q.push(v);
					}
			}
//			cerr <<  "Bucle bs" << endl;
  }
  return;
}



int main(){
	//lec();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout << fixed;
  cout.precision(5);
  int ntc,f  = 0;
	cerr << "Funcion" << endl;
  cin >> ntc;
	while(ntc--){
			int n,e;
			cin >> n >> e;
			int exist[n+4][n+4];
			if(f) cout << endl;
			f = 1;
			memset(exist,0,sizeof exist);

			g.assign(n+2,vi());
			FOR(i,e){
						int u , v ;
						cin >> u >> v;
						if(exist[v][u] || exist[u][v])continue;
            g[u].pb(v);
            g[v].pb(u);
            exist[u][v]  = 1;
			}
			bfs(0,n);
			loop(i,1,n){
					cout << dis[i] << endl;
			}
	}
	return 0;
}



