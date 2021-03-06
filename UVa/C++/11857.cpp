#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b; ++i)
#define SZ 1000100
#define X first
#define Y second
#define inf 1e9
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> Edge;


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

int main(){
    int n,e,u,v,w;
    while((scanf("%d %d",&n,&e)),n+e){
        int maxi = 0;
        vector<Edge> EdgeList;
        loop(i,0,e){
            scanf("%d %d %d",&u,&v,&w);
            EdgeList.pb(mp(w,mp(u,v)));
        }
        makeSet(n);
        sort(EdgeList.begin(),EdgeList.end());
        loop(i,0,e){
            Edge uvw = EdgeList[i];
            if(!isSameSet(uvw.Y.X,uvw.Y.Y)){
                unionSet(uvw.Y.X,uvw.Y.Y);
                maxi = max(uvw.X,maxi);
            }
        }
        if(componentes==1){
            printf("%d\n",maxi);
        }else{
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
