#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,b) for(int i=0;i<b;i++)
#define READ(file)  freopen(file, "r", stdin)
#define pb(a)    push_back(a)
#define X        first
#define Y        second
#define SZ       1000005
#define upA(a)   a*a
#define len(a) ((int)a.size())
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef pair<double,ii>  EDGE;
int r[SZ],p[SZ],sizeSet[SZ],componentes;

void makeSet(int N){
    int i;
    r[N];p[N];sizeSet[N];
    memset(r,0,sizeof r);
    memset(sizeSet,-1,sizeof sizeSet);
    loop(i,0,N+2)p[i]=i;
    componentes = N;
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
        componentes--;
        if (r[x] > r[y]){
            p[y] = x;
            sizeSet[x]+=sizeSet[y];
        }
        else{
            p[x] = p[y];
            sizeSet[y]+=sizeSet[x];
            if (r[x]==r[y])r[y]++;
        }
    }
    return;
}

double f(ii a , ii b){
    return ceil( sqrt( (double)(a.X-b.X)*(a.X-b.X) + (double)(a.Y-b.Y)*(a.Y-b.Y)) );
}

int main(){

    int c,n,m,x,y,flang=0;
    vector<ii> points;
    //READ("1216.txt");
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        points.clear();
        int comp  = 0,e=0;
        while(true && !false){
            scanf("%d",&x);
            if(x==-1)break;
            scanf("%d",&y);
            //printf("%d %d\n",x,y);
            points.pb(make_pair(x,y));
            comp++;
        }
        //printf("%d\n",comp);
        vector<EDGE> EdgeList;
        loop(i,0,comp){
            loop(j,i+1,comp){EdgeList.pb( make_pair( f(points[i] , points[j] ),ii(i+1,j+1) ) );e++;}
        }
        makeSet(comp);
        sort(EdgeList.begin(),EdgeList.end());
        FOR(i,e){
            EDGE EG  = EdgeList[i];
            if(!isSameSet(EG.Y.Y,EG.Y.X))unionSet(EG.Y.Y,EG.Y.X);
            if(componentes<=n){
                    printf("%0.0lf\n",EG.X);
                    break;
            }
        }
    }
    return 0;
}
