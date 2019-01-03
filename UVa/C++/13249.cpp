#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define LIM 110
#define INF 100000000
using namespace std;
int flody[LIM][LIM];

int FW(int d,int mini){
    int i,j,k;
    loop(k, 0, d) loop(i, 0, d) loop(j, 0, d){
        flody[i][j] = min(flody[i][j],(flody[i][k]+flody[k][j]));
    }
    int maxi = -1;
    loop(i,0,d)loop(j,0,d)if(i!=j)maxi = max(maxi,flody[i][j]);
    return ceil(maxi/(double)mini);
}
int main(){
    int N,S,i,j,d,A,B,C,ii,di,dj;
    while((scanf("%d%d",&N,&S))==2){
        memset(flody,0,sizeof  flody);
        loop(di,0,N) loop(dj,0,N)flody[di][dj] = INF;
        loop(ii,0,S){
            scanf("%d%d%d",&i,&j,&d);
            flody[i][j]=d;
            flody[j][i]=d;
        }
        scanf("%d%d%d",&A,&B,&C);
        int mini = min(A,min(B,C));
        printf("%d\n",FW(N,mini));
    }
    return 0;
}
