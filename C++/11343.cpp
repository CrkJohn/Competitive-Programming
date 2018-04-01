#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define X  first
#define Y second

using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;

struct line{
    point p,q;
    line( point _p , point _q) : p(_p) , q(_q) {}
};

double cross(point a, point b){
    return imag(conj(a)*b);
}


double dot(point a, point b){
    return real(conj(a)*b);
}

int ccw(point a, point b, point c){
    b-=a  ;  c-=a;
    if(cross(b,c) > 0) return 1;
    if(cross(b,c) < 0) return -1;
    if(dot(b,c) < 0) return 2;
    if(dot(b,b) < dot(c,c)) return -2;
    return 0;
}


bool iSS(const line &s, const line &t){
    return ccw(s.p,s.q,t.p) * ccw(s.p,s.q,t.q) <=0 && ccw(t.p,t.q,s.p) * ccw(t.p,t.q,s.q)<=0;
}


int main(){
    int casos;double x,y,xi,xj;
    //freopen("11343.txt","r",stdin);

    scanf("%d",&casos);
    while(casos--){
        vector<line> seg;
        int s; scanf("%d",&s);
        loop(i,0,s){
            scanf("%lf %lf %lf %lf",&x,&y,&xi,&xj);
            point p1(x,y) ; point p2(xi,xj);
            line l1 = line(p1,p2);
            seg.push_back(l1);
        }
        int flang,c=0;
        loop(i,0,s){
            line l1 = seg[i];
            flang = 1;
            loop(j,0,s){
                if(i!=j){
                    line l2 = seg[j];
                    if(iSS(l1,l2)){
                        flang = 0;
                        break;
                    }
                }
            }
            if(flang)c++;
        }
        printf("%d\n",c);
    }

    return 0;
}
