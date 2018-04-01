#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;++i)

using namespace std;
struct point{double x,y=0.0;point(double _x,double  _y):x(_x),y(_y){}};
struct line{double a,b,c;}; //  ax +by +c =0
double m(point p1 , point p2){return -(p1.y - p2.y) / (p1.x - p2.x);}
void pointsToLine(point p1, point p2, line &l)
{
    // l is a vertial line.
    if (p1.x == p2.x){
        l.a = 1.0;
        l.b = 0;
        l.c = -p1.x;
    }else{
        l.a = -(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}
int main(){
    double x1,y1,x2,y2,xp,yp;
    int q,i;
    scanf("%d",&q);
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    point p1(x1,y1);
    point p2(x2,y2);
    line l1,l2;
    pointsToLine(p1,p2,l1);
    double a = l1.a,b = l1.b;
    double m_per = b/a;
    loop(i,0,q){
        scanf("%f %f",&xp,&yp);
        //  ax +by +c =0
        l2.b = a;
        l2.a=-b;
        l2.c=(b*xp + a*xp);
        l2.b = l2.b*a;     l2.c=l2.c*a;
        l1.b = l1.b*l2.a ; l1.c=l1.c*l2.a;
        double y = l2.b + l1.b;
    }
    return 0;
}
