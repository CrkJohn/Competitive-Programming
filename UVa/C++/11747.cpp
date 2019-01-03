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
    #define X first
    #define Y second
    #define len(a) ((int)a.size())

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
        int ban=0,n,m,u,v,w;
        //freopen("11747.txt","r",stdin);
        while(scanf("%d%d",&n,&m),n+m){
            viii LiA;
            iniSet();
            loop(i,0,m){

                scanf("%d%d%d",&u,&v,&w);
                LiA.pb(mp(w,mp(u,v)));
            }
            sort(LiA.begin(),LiA.end());
            vector<int> res;
            loop(i,0,m){
                w = LiA[i].X;
                u = LiA[i].Y.X;
                v = LiA[i].Y.Y;
                if(findSet(u)!=findSet(v))UnionSet(u,v);
                else res.pb(w);
            }
            int lon  = res.size();
            if (res.empty()) printf("forest");
            else {
                printf("%d", res[0]);
                for (int i=1 ; i< lon ; i++)
                    printf(" %d", res[i]);
            }
            printf("\n");

        }
        return 0;
    }
