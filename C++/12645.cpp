#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i <b;i++)
#define len(a) ((int)a.size())
#define SZ 1100
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
int vis[SZ];
vi topo;
G adj;
int dfs(int src,int pass){
	vis[src] = 1;
	FOR(i,len(adj[src])){
		int u =  adj[src][i];
		if(!vis[u])dfs(u,pass);
	}
	if(!pass)topo.pb(src);
}


int main(){
	ios::sync_with_stdio(false);
	int n,e,u,v,pipelines;
	while(scanf("%d %d",&n,&e)!=EOF){
		adj.assign(n+1,vi());
		FOR(edge,e){
			scanf("%d%d",&u,&v);
			if(!v)continue;
			adj[u].pb(v);
		}
		memset(vis, 0, sizeof(vis));
		topo.clear();
		//find to leaf
		FOR(nodes,n+1){
			if(!vis[nodes]){
				dfs(nodes,0);
			}
		}
        reverse(topo.begin(),topo.end());
		memset(vis, 0, sizeof(vis));
		pipelines=0;
		FOR(nodes,len(topo)){
			v  = topo[nodes];
			if(!vis[v]){
				pipelines++;
				dfs(v,1);
			}
		}
		printf("%d\n",pipelines-1);
	}
	return 0;
}
