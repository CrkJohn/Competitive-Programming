#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define ms(a,c)    memset(a,c,sizeof(a))
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define pb(a)    push_back(a)
#define pf(a)    push_front(a)
#define tup(a,b) make_pair(a,b)
#define popb()   pop_back()
#define popf()   pop_front()
#define X        first
#define Y        second
#define LIM      100
#define INF      1000000010
#define SZ       1000005
#define upA(a)   a*a
#define base     10000
#define EPS      1e-9
#define LSOne(i) (i&(-i))

using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef deque<int> di;
typedef deque<ii> dii;
typedef di::iterator dit;
typedef vector<int> vi;
typedef set<int> si;
typedef set<large> sl;
typedef complex<double> im;
typedef vector<char*> vs;
typedef vector<large> bigint;

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


int main(){
    int n,i,u,v,largest,smallest;
    scanf("%d",&n);
    makeSet((2*n)+2);
    loop(i,0,n){
        scanf("%d %d",&u,&v);
        unionSet(u,v);
    }
    int mini = 999999999;
    int mayor = 0;
    vi a;
    a.
    loop(i,1,(2*n)+2){
        int tam = sizeSet[findSet(i)];
        if (tam!=-1){
            mini = min(mini,tam);
            mayor = max(mayor,tam);
        }
    }
    //loop(i,0,(2*n)+2) printf("%d ",sizeSet[i]);
    printf("%d %d\n",mini,mayor);
    return 0;
}
