#include <bits/stdc++.h>
#define FOR(i,a) for(i=2;i<=a;i++)
#define loop(i,a,b) for(i = a; i<b;i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> adj;

adj ListAdj;
int dis[100100],nodos;
int bfs(int src){
    int i,e,u;
    int rn=-1, rd=-1;
    queue<int> q;
    q.push(src);
    loop(i,1,nodos+1)dis[i]=-1;
    dis[src] = 0;
    while(!q.empty()){
        int v = q.front();q.pop();
        loop(e,0,(int)ListAdj[v].size()){
            u = ListAdj[v][e];
            if (dis[u]==-1){
                    dis[u] = dis[v] + 1;
                    q.push(u);
            }
        }
    }
    int r,j;
    //loop(r,1,nodos+1)printf("%d ",dis[r]);
    //puts("");
    loop(j,1,nodos+1){
        if(rd<dis[j]){rd = dis[j];rn = j;}
        //printf("El nodo %d tiene de profundidad %d,el nodo maximo es %d \n",j,dis[j],rn);

    }
    return rn;
}
int main(){
    int i,V;
    while (1){
        scanf("%d",&nodos);
        dis[nodos+1];
        if(nodos==-1)break;
        ListAdj.assign(nodos+3,vi());
        FOR(i,nodos){
            scanf("%d",&V);
            ListAdj[i].push_back(V);
            ListAdj[V].push_back(i);
        }
        int src = bfs(1);
        //printf("%d\n",src);
        int res = bfs(src);
        if (nodos == 2) puts("1");
        else   printf("%d\n",dis[res]%2 !=0 ? (dis[res]+1)/2 : dis[res]/2);
    }
    return 0;
}
