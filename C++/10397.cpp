#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define pb(a) push_back(a)
#define SZ       1000005
#define mp(x,y) make_pair(x,y)
#define Y second
#define X first


using namespace std;

typedef pair<int,int> ii;
typedef pair<double,ii>iii;
typedef vector<ii> vii;
typedef vector<iii> ListA;


int r[SZ],p[SZ],sizeSet[SZ];

void makeSet(int N){
    int i;
    r[N];p[N];sizeSet[N];
    memset(r,0,sizeof r);
    memset(sizeSet,-1,sizeof sizeSet);
    loop(i,1,N+2)p[i]=i;
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
    if (sizeSet[x]==-1) sizeSet[x] =1 ;
    if (sizeSet[y]==-1) sizeSet[y] = 1;
    if (!isSameSet(x,y)){
        if (r[x] > r[y]){
            p[y] = x;
            sizeSet[x]+=sizeSet[y];
        }
        else{
            p[x] = p[y      ];
            sizeSet[y]+=sizeSet[x];
            if (r[x]==r[y])r[y]++;
        }
    }
    return;
}
double hyp(ii p, ii p2){
    return ((p.first-p2.first)*(p.first-p2.first)) + ((p.second-p2.second)*(p.second-p2.second));
}
ListA ListAr(int P,vii G){
    ListA ListArc;
    int i,j;
    loop(i,0,P){
        ii p = G[i];
        loop(j,i+1,P){
            ii p2 = G[j];
            double dis = sqrt(hyp(p,p2));
            ListArc.pb(mp(dis,mp(i+1,j+1)));
        }
    }
    sort(ListArc.begin(),ListArc.end());
    return ListArc;
}



int main(){
    int N,i,x,y;
    while(scanf("%d",&N)==1){
        vii xY;
        loop(i,0,N){
            scanf("%d%d",&x,&y);
            xY.pb(mp(x,y));
        }
        int r;scanf("%d",&r);
        makeSet(N);
        loop(i,0,r){
            scanf("%d%d",&x,&y);
            unionSet(x,y);
        }
        ListA G = ListAr(N,xY);
        double res=0.0;
        for(int l=0; l<(int)G.size();l++){
            //printf("%d %d\n",G[l].Y.X,G[l].Y.Y);
            if(!isSameSet(G[l].Y.X,G[l].Y.Y)){
                unionSet(G[l].Y.X,G[l].Y.Y);
                res +=G[l].X;
            }
        }
        printf("%.2lf\n",res);

    }
    return 0;

}
