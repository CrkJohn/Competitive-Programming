#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define LIM 100100
#define INF 10000001
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef pair<int,ii> dii;
typedef vector<dii> vdii;
typedef vector<vi> G;
G graph;
int r[LIM],p[LIM],sizeSet[LIM];
void iniSet(int N){
    r[N+1];p[N+1];int i;
    memset(r,0,sizeof r);
    loop(i,0,N+1)p[i] = i;
}

int findSet(int x){
    if (x!=p[x])p[x] = findSet(p[x]);
    return p[x];
}

bool isSameSet(int x,int y){
    return findSet(x)==findSet(y);
}

void unionSet(int xx,int yy){
    int x = findSet(xx);
    int y = findSet(yy);
    if (!isSameSet(x,y)){
        if (r[x] > r[y]){
            p[y] = x;
        }
        else{
            p[x] = y;
            if (r[x]==r[y])r[y]++;
        }
    }
    return;
}


int bfs(int src,int en,int nodos){
    int i;queue<int> q;
    q.push(src);
    int dis[nodos];loop(i,0,nodos+1)dis[i] = INF;
    dis[src] = 0;
    int res= 0;
    while (!q.empty()){
        int u = q.front();q.pop();
        loop(i,0,(int)graph[u].size()){
            int v=graph[u][i].first; int w = graph[u][i].second;
            if (dis[v]==INF)
                dis[v] = dis[u] +1;
                res = max(res,w);
                if (v==en)return res;
                q.push(v);
        }
    }
}


int main(){
    int cas,cases,nodos,edge,i,u,v,edges,q,src,en;
    scanf("%d",&cases);
    vdii l_Arc;
    loop(cas,0,cases){
        scanf("%d %d",&nodos,&edge);
        graph.clear();
        l_Arc.clear();
        graph.assign(nodos+1,vi());
        iniSet(nodos);
        loop(i,0,edge){
            scanf("%d %d %d",&u,&v,&edges);
            l_Arc.push_back(make_pair(edges,make_pair(u,v)));
        }
        sort(l_Arc.begin(),l_Arc.end());
        loop(i,0,edge){
            int n_u= l_Arc[i].second.first ,n_v = l_Arc[i].second.second,n_w= l_Arc[i].first;
            if (!isSameSet(n_u,n_v)){
                unionSet(n_u,n_v);
                graph[n_u].push_back(make_pair(n_v,n_w));
                graph[n_v].push_back(make_pair(n_u,n_w));
            }
        }
        printf("Case %d\n",cas+1);
        scanf("%d",&q);
        loop(i,0,q){
            scanf("%d %d",&src,&en);
            printf("%d\n",dfs(src,en,nodos));
        }
        puts("");
    }
    return 0;
}
