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

double f(int low, int high, const vector<point> &vp){
	double ans = 1e9;
	//printf("%d %d\n",low,high);
	//system("pause");
	if(abs(high-low)<=1)return 1e9;
	else{
		int mid = (low+high)/2;
		ans = min(f(low,mid,vp),f(mid,high,vp));
		double com;
		for(int i = mid; i>=low; i--){
			for(int j = mid+1; j<=high;j++){
				if(vp[j].x - vp[i].x > ans)break;
				else ans  = min(ans,dist(vp[j],vp[i]));
			}
		}
	}
	return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	int ntc,points;double x,y;
	while(scanf("%d",&points),points){
		vp.clear();
		FOR(i,points){
			scanf("%lf %lf",&x,&y);
			vp.push_back(mp(x,y));
		}
		sort(vp.begin(),vp.end(),cmp);
		/*for(int i = 0 ; i<vp.size();i++){
			printf("(%lf,%lf)\n",vp[i].x,vp[i].y);
		}*/
		//printf("%d\n",vp.size());
		double res = f(0,vp.size()-1,vp);
		if(res > 10000)puts("INFINITY");
		else printf("%.4lf\n",res);

	}
	return 0;
}
