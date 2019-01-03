#include <bits/stdc++.h>
#define pb(a) push_back(a)


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> G;
G AdjList;
vi dfs_num , dfs_low, dfs_parent , articulation_vertex;
int dfsNumberCounter  = 1, dfsRoot, rootChildren;
const int DFS_WHITE = -1;




//taken from: Competitive Programming 2
void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v]==DFS_WHITE){ //tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++; // special case
      articulationPointAndBridge(v);
      if (dfs_low[v] >= dfs_num[u] && u != dfsRoot)articulation_vertex[u] = true;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      // updated dfs_low[u]
    }else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}





int main(){
  int V,u,v; string s;
  stringstream ss;
  while(scanf("%d",&V),V!=0){
	getchar();
	AdjList.clear();
	V++;

	AdjList.assign(V,vi());

	while(true){
		getline(cin,s);
		ss.clear();
		ss << s;
        ss >> u;if(u==0)break;
		while(ss>> v){
            AdjList[u-1].pb(v-1);
            AdjList[v-1].pb(u-1);
		}
	}
	dfsNumberCounter; dfs_num.assign(V, DFS_WHITE);
	dfs_low.assign(V, DFS_WHITE);
	dfs_parent.assign(V, DFS_WHITE);
	articulation_vertex.assign(V, 0);
	for (int i = 0; i < V; i++)
	if (dfs_num[i] == DFS_WHITE) {
	  dfsRoot = i; rootChildren = 0;
	  articulationPointAndBridge(i);
	  articulation_vertex[dfsRoot]=(rootChildren>1);
	}
	int ans = 0 ;
	for (int i = 0; i < V; i++)if (articulation_vertex[i]){
		ans++;
	}
	printf("%d\n",ans);
	}
	return 0;
}
