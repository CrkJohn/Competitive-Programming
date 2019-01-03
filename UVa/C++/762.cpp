#include<bits/stdc++.h>
#define loop(i,a,b) for(int  i = a; i<b ; i++)
#define FOR(i,b) for(int  i = 0; i<b ; i++)
#define REV2(i,b) for(int  i = b; i>=0 ; i = i+2)
#define len(a) ((int)a.size())
#define pb push_back
using namespace std;

typedef vector<int> vi;

const int LIM = 1e6;
map<string,int> ni;
map<int,string> in;

vi G[LIM];
int padre[LIM];

vi bfs(int &src, int &tgt , int &TM){
    //printf("%d %d\n",src,tgt);
    int vis[TM],u,v;
    memset(vis, 0 , sizeof vis);
    memset(padre,-1 , sizeof padre);
    padre[src] = src;
    queue<int> q;
    q.push(src);
    int flang = 0;
    while(!q.empty()){
        u = q.front();q.pop();
        vis[u] = 1;
        //printf("padre %d\n",u);
        if(u==tgt){flang = 1;break;}
        vis[u]  = 1;
        FOR(i,len(G[u])){
            v = G[u][i];
            //printf("%d ",v);
            if(!vis[v]){
                padre[v] = u;
                q.push(v);
            }
        }
    }
    //puts("Termine");
    vector<int> path;
    if(flang){
    int p = padre[tgt];
        while(p!=src){
            path.pb(p);
            path.pb(p);
            p = padre[p];
        }
        path.pb(src);
    }
    return path;
}

int main(){
    int n,nodes,eu,ev,V,fl= 0;
    char u[LIM],v[LIM];
    
    //freopen("762.txt","r",stdin);
    while(scanf("%d%*c",&n)==1){
        in.clear();ni.clear();
        FOR(i,LIM)G[i].clear();
        V = 1;
        if(fl)puts("");
        fl = 1;
        loop(i,0,n){
            scanf("%s %s ",&u,&v);
            eu = ni[u]; ev = ni[v];
            if(!eu){in[V] = u; ni[u] = V++;}
            if(!ev){in[V] = v; ni[v] = V++;}
            G[ni[u]].pb(ni[v]);
            G[ni[v]].pb(ni[u]);
        }
        //puts("Leer ultimo");
        scanf("%s %s ",&u,&v);
        //cout << u << " "  << v  << " "<< ni[u] << " "<< ni[v] << endl;
        if(!ni[u] || !ni[v])puts("No route");
        else{
            vi way = bfs(ni[u],ni[v],V);
            if(padre[ni[v]]==-1 || !way.size())puts("No route");
            else{
                int lon = way.size()-1;
                for (int i = lon ;i>-1;i--){
                printf("%s ",in[way[i--]].c_str());
                if(i>0)printf("%s\n",in[way[i]].c_str());
                }
                printf("%s\n",v);
            }
        }
    }
    return 0;
}
