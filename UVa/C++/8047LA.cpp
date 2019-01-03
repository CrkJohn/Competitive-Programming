#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i<b ; i++)
#define pb(a) push_back(a)
#define len(a) ((int)a.size())
using namespace std;

typedef vector<int> vc;
typedef vector<vc> Graph;
Graph G;

int  bfs(int src, int tgt){
    queue<int> q;
    q.push(src);
    int vis[27];memset(vis,0,sizeof vis);
    while(!q.empty()){
        int v = q.front(); q.pop();
        vis[v]=1;
        if(v == tgt)return 1;
        loop(i,0,len(G[v])){
            int u = G[v][i];
            if(!vis[u]){
                q.push(u);
            }
        }
    }
    return 0;
}


int main(){
    int M,N;
    char u,v,U[51],V[51];
    //freopen("8047LA.txt","r",stdin);
    while ((scanf("%d %d\n",&M,&N))==2){
        G.clear();
        G.assign(27,vc());
        loop(i,0,M){
            scanf("%c %c\n",&u,&v);
            G[u-'a'].pb(v-'a');
        }
        loop(i,0,N){
            scanf("%s %s\n",&U,&V);
            if(strlen(U)!=strlen(V))puts("no");
            else{
                int lon = strlen(U),flang = 0;
                loop(j,0,lon){
                    int r = bfs(U[j]-'a',V[j]-'a');
                    if(!r){flang = 1;break;}
                }
                (flang) ?  puts("no") : puts("yes");
            }
        }
    }
    return 0;
}
