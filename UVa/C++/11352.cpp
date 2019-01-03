#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define X  first
#define Y second

using namespace std;
typedef pair<int,int> ii;

int pos[110][110];
int dis[110][110];

int x[8] = {-2,-2,-1,1,-1,1,2,2};
int y[8] = {-1,1,-2,-2,2,2,-1,1};


int rx[8] = {-1 ,-1,-1,0,0,1,1,1};
int ry[8] = {-1,0,1,-1,1,-1,0,1};

int r,c;
int ri,rj,fi,fj;

void let(int i , int j){
    loop(p , 0 , 8){
        int a = i + x[p] , b = j + y[p];
        if(a>=0 && a<r && b>=0 && b<c){
            if(pos[a][b]!=2 && pos[a][b]!=-2)pos[a][b] =-1;
        }
    }
}

int bfs(int i , int j){
    memset(dis , -1, sizeof dis);
    queue<ii> q;
    dis[i][j] = 0;
    q.push( ii(i,j) );
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if( u.X == fi  &&  u.Y== fj )return dis[u.X][u.Y];
        loop(d,0,8){
            int a  = u.X + rx[d];
            int b = u.Y + ry[d];
            if(a>=0 && a<r && b>=0 && b<c){
                if( (pos[a][b]!=-1 && pos[a][b]!=-2)&& dis[a][b]==-1){
                    dis[a][b] = dis[u.X][u.Y] + 1;
                    q.push(ii(a,b));
                }
            }
        }
    }
    return -1;
}


int main(){
    int T;
    char lec[110];
    scanf("%d ",&T);
    while(T--){
        scanf("%d %d ",&r,&c);
        memset(pos , 0 , sizeof pos);
        loop(i,0,r){
            scanf("%s%*c", lec);
            loop(j,0,c){
                if(lec[j] == 'Z') {
                    let(i,j);
                    pos[i][j] = -2;
                }
                if(lec[j] == 'A'){
                        ri = i;
                        rj = j ;
                }
                if(lec[j] == 'B'){
                    fi = i;
                    fj = j;
                    pos[i][j]=2;
                }
            }
        }
        int res = bfs(ri,rj);
        if(res==-1)printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",res);

    }
    return 0;
}
