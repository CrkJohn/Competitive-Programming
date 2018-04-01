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

int r,c,maze[1000][1000];

int dijkstra(){
    ii par;int d,u;
    priority_queue< ii , vector<ii>, greater<ii> >  pq;
    int dis[r+3][c+3];
    loop(i,0,r+3)loop(j,0,c+3)dis[i][j] = INF;

    pq.push(ii(0,src));
    dis[0][0] = maze[0][0];
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
    return dis[r][c];
}


int main(){
    int T,r,c;
    //freopen("10986.txt","r",stdin);
    scanf("%d",&T);
    for(int c=1 ; c<= T; c++){
        scanf("%d %d",&r,&c);
        maze[r][c];
        loop(i,0,r){
            loop(j,0,c){
                scanf("%d",&maze[i][j]);
            }
        }

    }
    return 0;
}
