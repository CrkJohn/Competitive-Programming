#include<bits/stdc++.h>
#define loop(i,a,b) for(int i =a ; i <b  ; ++i)
#define FOR(i,b) for(int i =0 ; i <b  ; ++i)
#define READ(file)  freopen(file, "r", stdin)

using namespace std;

typedef complex<double> point;
typedef vector<point> polygon;

namespace std
{
	bool operator<(point a, point b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}

double cross(point a, point b) { return imag(conj(a) * b); }

double area2(point a, point b, point c) { return cross(b - a, c - a); }

double a2(double a){ return a*a;}

double dist(point a , point b){     return sqrt(a2(real(a)-real(b)) + a2(imag(a)-imag(b)));}

polygon convex_hull(vector<point> &P)
{
	int n = P.size(), k = 0;
	vector<point> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}

double perimento_CH(polygon P){
    double per = .0;
    int lon = P.size();
    loop(i,0,lon-1)per += dist(P[i],P[i+1]);
    per += dist(P[0],P[lon-1]);
    return per;
}

int main(){
    int c;double x,y;
    scanf("%d",&c);
    FOR(cases,c){
        double lon; int nails;
        polygon P;P.clear();
        scanf("%lf %d",&lon,&nails);
        FOR(i,nails){
            scanf("%lf %lf",&x,&y);
            point tmp(x,y);
            P.push_back( tmp );
        }
        polygon P1 = convex_hull(P);
        double per = perimento_CH(P1);
        //printf("%lf %lf %d \n",lon , per,per<lon);
        if(lon  > per)printf("%.5lf\n",lon);
        else printf("%.5lf\n",per);

    }
    return 0;
}
