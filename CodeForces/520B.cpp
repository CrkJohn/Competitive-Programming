#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define forn(i,a,b) for(int i = a; i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define eps 1e-9
#define INF 1e9


using namespace std;

const int RED = 2;
const int BLUE = 1;

const int maxn = 10100;

void dijkstra(const int &s, const int &t){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	FOR(i,maxn)dis[i]=INF;
	dis[s]=0;
	pq.push(ii(0, s));
	while (!pq.empty()){
		ii par=pq.top(); pq.pop();
		int d=par.fi; int u=par.se;
		if (d>dis[u]) continue;
		ii v;
		v.se =
		if (dis[u]+v.Y < dis[v.X]){
			dis[v.X]= dis[u] + v.Y;
			pq.push(ii(dis[v.X], v.X));
		}
	}
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	cin >> n>>m;

	return 0;
}
