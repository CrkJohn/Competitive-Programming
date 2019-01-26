#include<bits/stdc++.h>

using namespace std;

struct Point{
	long long x,y;
	void Get ()
	{
		scanf("%lld%lld",&x,&y);
	}
}data[10005];

int Gcd (int x,int y)
{
	return !y?x:Gcd(y,x%y);
}

int main ()
{
	int T,n,i;
	__int64 inside,on;
	scanf("%d",&T);
	while(1){
		on=0;
		double area=0;
		scanf("%d",&n);
		if(n==0)break;
		for (i=0;i<n;i++)
			data[i].Get();
		data[n]=data[0];
		for (i=0;i<n;i++)
		{
			area+=data[i+1].x*data[i].y-data[i].x*data[i+1].y;
			on+=Gcd(fabs(data[i].x-data[i+1].x),fabs(data[i].y-data[i+1].y));
		}
		area=fabs(area/=2.0);
		inside=area+1-on/2.0;
		printf("%d\n",inside);
	}
	return 0;
}
