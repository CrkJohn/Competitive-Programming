#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define ms(a,c)    memset(a,c,sizeof(a))
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define pb(a)    push_back(a)
#define pf(a)    push_front(a)
#define mp(a,b) make_pair(a,b)
#define popb()   pop_back()
#define popf()   pop_front()
#define LIM      1000000
#define INF      1000000010
#define SZ       1000005
#define upA(a)   a*a
#define base     10000
#define EPS      1e-9
#define LSOne(i) (i&(-i))

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;

int r[LIM],p[LIM];
void iniSet(){
    loop(i,0,LIM){
        r[i] = 0;
        p[i] = i;
    }
}

int findSet(int x){
    if(x!=p[x])p[x] = findSet(p[x]);
    return p[x];
}

void UnionSet(int x,int y){
    int rx = findSet(x),ry = findSet(y);
    if(r[rx]<r[ry]) p[rx] = ry;
    else if(r[rx]>r[ry]) p[ry] = rx;
    else{
        p[ry] = rx;
        r[rx]++;
    }
}


int main(){
    int flang=0,N,K,M,u,v,w;

    while(scanf("%d",&N)==1){
        iniSet();
        viii LiA;
        if(flang)puts("");
        flang=1;
        int Mmst=0,Smst=0;

        loop(i,0,N-1){
            scanf("%d %d %d",&u,&v,&w);
            Mmst+=w;
        }

        scanf("%d",&M);
        loop(i,0,M){
                       scanf("%d %d %d",&u,&v,&w);

            LiA.pb(mp(w,mp(u,v)));
        }
        scanf("%d",&K);
        loop(i,0,K){
            scanf("%d %d %d",&u,&v,&w);
            LiA.pb(mp(w,mp(u,v)));
        }

        sort(LiA.begin(),LiA.end());
        int lon = LiA.size();
        loop(i,0,lon){
            int wi = LiA[i].first , ui = LiA[i].second.first , vD = LiA[i].second.second;
            if (findSet(ui)!=findSet(vD)){
                Smst += wi;
                UnionSet(ui,vD);
            }
        }

        printf("%d\n%d\n",Mmst,Smst);

    }
        return 0;
}
