#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i<b ; ++i)
#define pb(a)  push_back(a)

using namespace std;
typedef vector<int> vi;
typedef vector<vi>Graph;
Graph G;
int padre[80];

vector<int> bfs(const int &src,const int &tgt){
    memset(padre,-1 , sizeof padre);
    queue<int> q;
    q.push(src);
    padre[src] = src;
    while(!q.empty()){
        int u =  q.front(); q.pop();int lon = G[u].size();
        if(u == tgt)break;
        loop(i,0,lon){
            int v = G[u][i];
            if(padre[v]==-1){
                padre[v] = u;
                q.push(v);
            }
        }
    }
    vector<int> path;
    int p = padre[tgt];
    while(p!=padre[p]){
        path.pb(p);
        p = padre[p];
    }
    path.pb(src);
    return path;
}

int main(){
    //freopen("10009UVa.txt","r",stdin);
    map<string,int> Gb;
    map<int,string> Fpath;
    string lec,u,v;stringstream ss;
    int c,e,q,n=1,flang = 0;
    scanf("%d",&c);
    for(int cases = 0 ; cases<c;cases++){
        scanf("%d %d ",&e,&q);
        if(flang)puts("");
        flang = 1;
        G.clear();
        G.assign(80,vi());
        loop(i,0,e){
            ss.clear();getline(cin,lec);
            ss << lec; ss >> u >> v;
            //Create Graph u->v v->u
            int exist = Gb[u];
            int exist2 = Gb[v];
            if(!exist && !exist2){
                Gb[u] = n;Fpath[n++] = u;
                Gb[v] = n;Fpath[n++] = v;
            }else if(exist && !exist2){
                Gb[v] = n;Fpath[n++] = v;
            }else if(!exist && exist2){
                 Gb[u] = n;Fpath[n++] = u;
            }
            G[Gb[u]].pb(Gb[v]);
            G[Gb[v]].pb(Gb[u]);
        }

        loop(Query,0,q){
            ss.clear();getline(cin,lec);
            ss << lec; ss >> u >> v;
            vector<int> res;res.clear();
            int src = Gb[u]; int tgt = Gb[v];
            res = bfs(src,tgt);
            int lon = res.size()-1;
            for (int i = lon ;i>-1;i--){
                string nodo = Fpath[ res [i] ];
                cout <<nodo[0];
            }
            cout<<v[0];
            puts("");
        }
    }
    return 0;
}
