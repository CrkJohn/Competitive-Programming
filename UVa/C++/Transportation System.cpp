#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i<b ; ++i)
#define LIM 1001
#define mp(a,b) make_pair(a,b)


using namespace std;
typedef pair<int,int> ii;
typedef pair<double,ii> dii;
typedef vector<dii> LisA;

int r[LIM],p[LIM];
LisA LiA;

void iniSet(){
    loop(i,0,LIM){
        r[i] = 0; p[i] = i;
    }
}

int findSet(int x){
    if(x!=p[x]) p[x] = findSet(p[x]);
    return p[x];
}

void unionSet(int x , int y){
    int rx = findSet(x), ry  = findSet(y);
    if(rx==ry)return;
    if(r[rx]<r[ry]) p[rx] = ry;
    else if(r[rx]>r[ry])p[ry] = rx;
    else{
        p[ry] = rx;
        r[rx]++;
    }
}

double dis(ii x , ii y){
    int h= ((x.first-y.first)*(x.first-y.first)) + ((x.second-y.second)*(x.second-y.second));
    return sqrt(h);
}

int G(vector< pair<int,int> > points,int n){
        LiA.clear();
        int lon=0;
        for(int i=0;i<n;i++){
            for(int j =  i+1; j<n ; j++){
                double w = dis(points[i],points[j]);
                //printf("%lf\n",w);
                LiA.push_back(mp(w,mp(i+1,j+1)));
                lon++;
            }
        }
        return lon;
}


int main(){
    int T,n,x,y;
    double r;
    //freopen("TS.txt","r",stdin);
    scanf("%d",&T);
    for(int c = 1 ; c<=T;c++){
        LiA.clear();
        scanf("%d%lf ",&n,&r);
        vector<ii> points;
        loop(p,0,n){
            scanf("%d%d",&x,&y);
            points.push_back(make_pair(x,y));
        }
        int lon  = G(points,n);
        sort(LiA.begin(),LiA.end());
        /*loop(i,0,lon){
            printf("%lf %d %d\n",LiA[i].first,LiA[i].second.first,LiA[i].second.second);
        }*/
        iniSet();
        int state=1;
        double roads=0.0,railroads=0.0;
        loop(i,0,lon){
            double wi = LiA[i].first;
            int u = LiA[i].second.first ,v = LiA[i].second.second;
            //printf("%d - %lf -> %d\n",u,wi,v);
            if(findSet(u)!=findSet(v)){
                if(wi>r){
                    railroads+=wi;
                    state++;
                }else{ roads +=wi;}
                unionSet(u,v);
            }
        }
        printf("Case #%d: %d %.lf %.lf\n",c,state,roads,(railroads));
    }
    return 0;
}
