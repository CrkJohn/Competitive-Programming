#include<bits/stdc++.h>
#define se second
#define fi first
#define len(str) (int)(str.length())
#define pb push_back
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i = a ; i<b;i++)
#define SZ  1010
#define fi first
#define se second
using namespace std;
typedef vector<string> vs;
typedef pair<int,int> ii;
//typedef map<string,vs>  G;
typedef map<string,string> father;

using namespace std;

int graph[SZ][SZ];

int moveI[] = {-1,1,0,0};
int moveJ[] = {0,0,1,-1};
int F,C;
int isLet(int i , int j){
    return 0<=i && i<F && 0<=j && j<C;
}


void bfs(ii src, ii tgt){
    queue<ii> q;
    q.push(src);
    graph[src.fi][src.se] = 0;
    while(!q.empty()){
        ii u = q.front();q.pop();
        if(u.fi == tgt.fi &&  u.se == tgt.se)return;
        FOR(i,4){
            int h = u.fi + moveI[i] , k = u.se + moveJ[i];
            if(isLet(h,k) &&  graph[h][k]!=-2 && graph[h][k]==-1){
                q.push(ii(h,k));
                graph[h][k] = graph[u.fi][u.se] + 1;
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	int boom,fBoom,cntBoom,cBoom,srcX,srcY,tgtX,tgtY;
	while(1){
        cin >> F >> C;
        if(F+C==0)break;
        cin >> boom;
        memset(graph,-1,sizeof graph);
        FOR(i,boom){
            cin >> fBoom;
            cin >> cntBoom;
            FOR(j,cntBoom){
                cin >> cBoom;
                graph[fBoom][cBoom] = -2;
            }
        }
        cin >> srcX >> srcY;
        cin >> tgtX >> tgtY;
        bfs(ii(srcX,srcY),ii(tgtX,tgtY));
        cout << graph[tgtX][tgtY] <<'\n';
    }
    return 0;
}
