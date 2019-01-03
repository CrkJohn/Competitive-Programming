#include <bits/stdc++.h>
#define loop(i,a,b) for( int  i = a ; i<b ;++i)
#define X first
#define Y second


using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> Nodo_w;
typedef vector<Nodo_w> LisA;

LisA adjList;

const int LIM = 2009;
const int INF = 1e9;

int n;

int dijkstra(int src, int tgt){
    ii par;int d,u;
    priority_queue< ii , vector<ii>, greater<ii> >  pq;
    int dis[n+3];
    loop(i,0,n+3) dis[i] = INF;
    pq.push(ii(0,src));
    dis[src] = 0;
    while(!pq.empty()){
        par = pq.top(); pq.pop();
        d = par.X ;  u  = par.Y;
        loop(j,0,(int)adjList[u].size()){
            ii v = adjList[u][j];
            if(dis[u]+v.Y < dis[v.X]){
                dis[v.X] = dis[u] + v.Y;
                pq.push(ii(dis[v.X],v.X));
            }
        }
    }
    return dis[tgt];
}

int main(){
    int T,m,src,tgt,u,v,w;
    //freopen("10986.txt","r",stdin);
    scanf("%d",&T);
    for(int c=1 ; c<= T; c++){
        scanf("%d %d %d %d",&n,&m,&src,&tgt);
        //puts("aca");
        adjList = LisA(n+2);
        loop(i,0,m){
            scanf("%d%d%d",&u,&v,&w);
            adjList[u].push_back(ii(v,w));
            adjList[v].push_back(ii(u,w));
        }
        if (m == 0){ printf("Case #%d: unreachable\n",c);continue;}
        int r = dijkstra(src,tgt);
        if (r == INF)printf("Case #%d: unreachable\n",c);
        else printf("Case #%d: %d\n",c,r);
    }
    return 0;
}
