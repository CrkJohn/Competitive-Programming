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
#define EPS      1e-32
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


struct point{
    double x,y;
    point(){double x=y=0.0;}
    point(double _x,double _y): x(_x) , y(_y){}
};


struct circle{
     point c ; double r;
     circle(){point c = point(0.,0.); double r=0.0;}
     circle(point _c, double _r): c(_c.x,_c.y), r(_r){}
};




struct line{double a,b,c;};


void pointsToLine(point a, point b, line &l){
    if (fabs(a.x-b.x)<EPS){
        l.a = 1.0 ; l.b = 0.0 ; l.c = -a.x;
    }else{
        l.a  = -(double)(a.y-b.y) / (a.x-b.x);
        l.b = 1.0;
        l.c = -(double)(l.a * a.x) - a.y;
    }
}

bool areP(line l1, line l2){
    return (fabs(l1.a-l2.a) < EPS)  && (fabs(l1.b-l2.b) < EPS) ;
}

bool areIstersect(line l1, line l2 , point &p){
    if (areP(l1,l2))return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b)>EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y   = -(l2.a * p.x + l2.c);
    return true;
}


void pointSlopeToLine(point p, double m , line &l){
    l.a = -m;
    l.b = 1;
    l.c = -((l.a*p.x)+(l.b*p.y));
}

line closestPoint(line l , point p, point &ans){
    line perpendicular;
    int b=0;
    if (fabs(l.b)< EPS ){
        ans.x = -(l.c);
        ans.y = p.y;
        b=1;
    }
    if (fabs(l.a)< EPS && !b){
        ans.x = p.x;
        ans.y = -(l.c);
    }
    pointSlopeToLine(p,1/l.a,perpendicular);
    areIstersect(l,perpendicular,ans);
    return perpendicular;
}


double Ar(double a, double b, double c){
  double s = (a+b+c)/2.;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

double hypt(double x, double y){
    return sqrt((x*x)+(y*y));
}



double dist(point a, point b){
    return hypt(a.x-b.x,a.y-b.y);
}

double rCircumCircle(double ab, double bc, double ca){
        return ab* bc * ca / (4.0* Ar(ab,bc,ca));
}

double rCircumCircle(point a, point b, point c){
   return rCircumCircle(dist(a,b),dist(b,c),dist(c,a));
}

void Pmedium (point a, point b,point &m){
    m.x  = (b.x+a.x)/2.;
    m.y  = (b.y+a.y)/2.;
}
int main(){
    int cases;
    point a,b,c,d,m1,m2,Cr,ans1,ans2;
    double x,y;
    scanf("%d",&cases);
    while(cases--){
        scanf("%lf %lf",&x,&y);a = point(x,y);
        scanf("%lf %lf",&x,&y);b = point(x,y);
        scanf("%lf %lf",&x,&y);c = point(x,y);
        scanf("%lf %lf",&x,&y);d = point(x,y);
        double R = rCircumCircle(a,b,c);
        line l1,l2,ml,ml2;
        pointsToLine(a,b,l1);
        //printf("l1 %lf x+ %lf y+ %lfc =0\n",l1.a,l1.b,l1.c);
        pointsToLine(b,c,l2);
        Pmedium(a,b,m1);
        Pmedium(b,c,m2);
        ml = closestPoint(l1 , m1, ans1);
        //printf("Mediatriz l1 %lfx+ %lfy+c %lf=0\n",ml.a,ml.b,ml.c);
        ml2 = closestPoint(l2, m2,ans2);
        //printf("Mediatriz l2 %lfx+ %lfy+c %lf=0\n",ml2.a,ml2.b,ml2.c);
        areIstersect(ml,ml2,Cr);
        double Dq = dist(Cr,d);
        if (R<Dq) printf("Accepted\n");
        else printf("Rejected\n");


    }
    return 0;
}
