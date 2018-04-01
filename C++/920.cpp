#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i = a ; i<b;i++)

#define mp(a,b) make_pair(a,b)
#define len(a) ((int)a.size())
#define x first
#define y second
#define eps 1e9

using namespace std;

typedef pair<double,double> point;

vector<point> vp;

bool cmp(point a , point b){
	if(fabs(a.x-b.x<eps))return a.x<b.x;
	return a.y < b.y;
}
double dist(point a, point b){
	return sqrt( ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y)));
}

double f(vector<point> &vp){
	double res = 0.,x_,m;int lon = len(vp);
	double ymax = vp[vp.size()-1].y,b;
	//reverse(vp.begin(),vp.end());
	/*puts("Reverse");
	for(int i = 0 ; i<vp.size();i++){
			printf("(%lf,%lf)\n",vp[i].x,vp[i].y);
	}*/	
	for(int i = lon-2;i>=0;i--){
		//printf("Ymax : %lf \n",ymax);
		if(ymax > vp[i].y)continue;
		m = (vp[i].y -vp[i+1].y)/(vp[i].x-vp[i+1].x);
		//printf("m : %lf\n",m);
		b = vp[i].y - vp[i].x*m;
		x_ = (ymax - b) /m;
		//printf("x: %lf\n",x_);
		res += dist(vp[i],make_pair(x_,ymax));
		ymax = max(ymax,vp[i].y);
		
	}
	return res;
}


int main(){
	//freopen("in.txt","r",stdin);
	int ntc,points;double x,y;
	scanf("%d",&ntc);
	while(ntc--){
		vp.clear();
		scanf("%d",&points);
		FOR(i,points){
			scanf("%lf %lf",&x,&y);
			vp.push_back(mp(x,y));		
		}
		
		
		
		sort(vp.begin(),vp.end(),cmp);
		/*for(int i = 0 ; i<vp.size();i++){
			printf("(%lf,%lf)\n",vp[i].x,vp[i].y);
		}*/
		if(points==1)puts("0.00");
		else{
			printf("%.2lf\n",f(vp));
		}
	}
	return 0;
}
