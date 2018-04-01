#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b; ++i)
#define FOR(i,b) for(int i = 0 ; i<b ; ++i)
#define SZ 1000100
#define X first
#define Y second
#define inf 1e9
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ent(a) a[0]-'0'
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
    int cases,nodos,c,W;
    char w[9];
    //freopen("1208.txt","r",stdin);
    scanf("%d",&cases);
    FOR(ca,cases){
        c =  0;
        scanf("%d",&nodos);
        vector<Edge> EdgeList;
        makeSet(nodos+1);
        loop(u,0,nodos){
            loop(v,0,nodos){
                scanf("%s ",&w);sscanf(w,"%d",&W);
                //printf("%d\n",W);
                if(ent(w)!=0){EdgeList.pb(mp(W,mp(u,v)));c++;}
            }
        }
        printf("Case %d:\n",ca+1);
        sort(EdgeList.begin(),EdgeList.end());
        FOR(i,c){
            Edge e = EdgeList[i];
            if(!isSameSet(e.Y.X,e.Y.Y)){
                unionSet(e.Y.X,e.Y.Y);
                printf("%c-%c %d\n",e.Y.X+'A',e.Y.Y+'A',e.X);
            }
        }
    }
    return 0;
}
