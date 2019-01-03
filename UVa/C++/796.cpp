#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define loop(i,a,b) for(int i = a ; i< b ; i++)
#define FORI(i,b) for(int i = 0 ; i<= b ; i++)
#define FOR(i,b) for(int i = 0 ; i< b ; i++)
#define len(a) ((int)a.size())

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> G;
typedef vector<ii> Bridge;
G AdjList;
Bridge B;
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

      if (dfs_low[v] >= dfs_num[u])articulation_vertex[u] = true;
	  if (dfs_low[v] > dfs_num[u]){
            B.pb(ii(min(u,v),max(u,v)));
	  }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      // updated dfs_low[u]
    }else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}





int main(){
  int V,u,v,c,flang = 0; string s;
  stringstream ss;
  //freopen("796.txt","r",stdin);
  while(scanf("%d", &V)==1){
        AdjList = G(V);
        FOR(i,V){
            scanf("%d (%d)", &u, &c);
            FOR(j,c){
                scanf("%d", &v);
                AdjList[u].push_back(v);
               // g[en].push_back(st);
            }
    }
	dfs_low.clear();dfs_num.clear();dfs_parent.clear();articulation_vertex.clear();
	dfsNumberCounter; dfs_num.assign(V, DFS_WHITE);
	dfs_low.assign(V+1, DFS_WHITE);
	dfs_parent.assign(V+1, DFS_WHITE);
	articulation_vertex.assign(V, 0);
	B.clear();
	for (int i = 0; i < V; i++)
	if (dfs_num[i] == DFS_WHITE) {
	  dfsRoot = i; rootChildren = 0;
	  articulationPointAndBridge(i);
	  articulation_vertex[dfsRoot]=(rootChildren>1);
	}
	sort(B.begin(),B.end());
	printf("%d critical links\n",len(B));
        loop(i,0,len(B)){
            printf("%d - %d\n",B[i].first,B[i].second);
        }

    puts("");
	}
	return 0;
}
