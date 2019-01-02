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
int loop[maxn][maxn];
int r,c;
vector<string> g;

int type;
ii iiLoop;
int ans;
void dfs(ii pos){
  int i;
	if(g[pos.fi][pos.se]=='S'){
      i = 0;
	}
	if(g[pos.fi][pos.se]=='W'){
			i =  1;
	}
	if(g[pos.fi][pos.se]=='N'){
		 i = 2;
	}
	if(g[pos.fi][pos.se]=='E'){
		 i = 3;
	}
	int h  = pos.fi + dy[i], k = pos.se + dx[i];
//	cerr << h << " " << k  << endl;
	if(0<=h && h<r  && 0<=k && k <c){
			if(loop[h][k]!=-1){
						type = 2;
						iiLoop.fi =  loop[pos.fi][pos.se] -  loop[h][k];
						iiLoop.se = loop[h][k];
						return;
			}
			loop[h][k] =  loop[pos.fi][pos.se]  + 1;
			dfs(ii(h,k));
	}else{
			type = 1;
			ans = loop[pos.fi][pos.se];
			return;
	}
}



int main(){
//	lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int iniC;
	while(cin >> r >> c  >> iniC, r+c+iniC){
//			cerr << "Strat" << endl;
			g.clear();
			g.resize(r+1);
			FOR(i,r){
					cin >> g[i];
			}
//			FOR(i,r){
//				cerr << g[i] << endl;}
//			cerr << endl;
			type = 0;
			FOR(i,r)FOR(j,c)loop[i][j] = -1;
			loop[0][iniC-1] =  0;
			dfs(ii(0,iniC-1));
			/*FOR(i,r){
				FOR(j,c){
						 cerr << loop[i][j] << " " ;
				}
				cerr	 << endl;
			}*/
			if(type == 1){
					cout << ans+1 <<" step(s) to exit" << endl;
			}else{
					cout << iiLoop.se;
					cout << " step(s) before a loop of ";
					cout << iiLoop.fi+1;
					cout << " step(s)\n";
			}
	}
	return 0;
}
